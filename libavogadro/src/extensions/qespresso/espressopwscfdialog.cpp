/**********************************************************************
  EspressoPWScfExtension

  Copyright (C) 2010 David C. Lonie

  This library is free software; you can redistribute it and/or modify
  it under the terms of the GNU Library General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#include "espressopwscfdialog.h"

#include "espressoextension.h"

#include <avogadro/molecule.h>
#include <avogadro/atom.h>

#include <openbabel/generic.h>

#include <QtGui>
#include <vector>
#include <QtXml>


const double pi = 3.1415926535897932384626433;

using namespace Avogadro;

namespace Espresso {

  EspressoPWscfDialog::EspressoPWscfDialog(QWidget *parent, EspressoExtension *ext)
    : QDialog(parent),
      m_ext(ext) {

    // Extension connections
//    connect(m_ext, SIGNAL(resetExtension()), this, SLOT(reset()));
//    connect(m_ext, SIGNAL(updateExtension(Avogadro::Molecule*)),
//            this, SLOT(update(Avogadro::Molecule*)));

    m_config = new EspressoPWscfConfig(this);

    this->setLayout(new QVBoxLayout);
    QTabWidget *tabs = new QTabWidget();
    this->layout()->addWidget(tabs);
    tabs->addTab(m_config->controlWidget(), "Control");
    tabs->addTab(m_config->systemWidget(), "System");
    tabs->addTab(m_config->electronsWidget(), "Electrons");
    tabs->addTab(m_config->speciesWidget(), "Species");
    // Dialog connections
//    connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(hide()));
    QPushButton *runButton = new QPushButton("Run");
    this->layout()->addWidget(runButton);
    connect(runButton, SIGNAL(clicked()), this, SLOT(write()));

    QDomDocument doc("elements");
    QFile file("/home/iazzi/projects/kalzium/libscience/data/elements.xml");
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

//    qDebug() << doc.toString();
    QDomNodeList atoms = doc.elementsByTagName("atom");
    for (int i=0;i<atoms.size();i++) {
        int Z;
        double mass;
        QString sym;
        QString pp = "";
        QDomNodeList data = atoms.at(i).childNodes();
        for (int j=0;j<data.size();j++) {
            QString dr = data.at(j).toElement().attribute("dictRef");
            if (dr=="bo:symbol") {
                sym = data.at(j).toElement().attribute("value");
            } else if (dr=="bo:mass") {
                mass = data.at(j).toElement().text().toDouble();
            } else if (dr=="bo:atomicNumber") {
                Z = data.at(j).toElement().text().toInt();
            }
        }
//        qDebug() << "adding" << sym << "( Z =" << Z << ") mass =" << mass;
        m_masses.resize(Z+1);
        m_symbols.resize(Z+1);
        m_pseudopotentials.resize(Z+1);
        m_masses[Z] = mass;
        m_symbols[Z] = sym;
        m_pseudopotentials[Z] = pp;
//        qDebug() << "added" << sym << "( Z =" << Z << ") mass =" << mass;
    }
  }


//  void EspressoPWscfDialog::reset () {
//  }

//  void EspressoPWscfDialog::update (Molecule *mol) {
//    mol_ = mol;
//    nat = mol->numAtoms();
//    ntyp = 0;
//    std::vector<bool> present;
//    present.insert(present.begin(), 200, false);
//    for (int i = 0; i < mol->atoms().size(); i++) {
//        if (!present[mol->atom(i)->atomicNumber()]) {
//            present[mol->atom(i)->atomicNumber()] = true;
//            ntyp++;
//        }
//    }
//    if (mol->OBUnitCell()) {
//        a = mol->OBUnitCell()->GetA();
//        b = mol->OBUnitCell()->GetB();
//        c = mol->OBUnitCell()->GetC();
//        cosBC = mol->OBUnitCell()->GetAlpha();
//        cosAC = mol->OBUnitCell()->GetBeta();
//        cosAB = mol->OBUnitCell()->GetGamma();
//    }
//  }

  void EspressoPWscfDialog::readMolecule () {
      species.clear();
      QList<Atom*> atoms = mol_->atoms();
      for (int i=0;i<atoms.size();i++) {
          Atom &a = *atoms[i];
          QString sym = m_symbols[a.atomicNumber()];
          if (!species.contains(a.atomicNumber())) {
              species.append(a.atomicNumber());
          }
      }
  }

  void EspressoPWscfDialog::run (Molecule *mol) {
      mol_ = mol;
      if (mol==NULL) return;
      readMolecule();
      QStringList snames;
      for (int i=0;i<species.size();i++) {
          snames.append(m_symbols[species[i]]);
      }
      m_config->setSpecies(snames);
      show();
  }

  void EspressoPWscfDialog::write () {
      QString input = "";
      input.append(m_config->controlSection());
      input.append(m_config->systemSection());
      input.append(m_config->electronsSection());
      QMap<QString,QString> mpp = m_config->pseudopotentials();
      QString atomic_species = "ATOMIC_SPECIES\n";
      for (int i=0;i<species.size();i++) {
          int Z = species[i];
          QString sym = m_symbols[Z];
          atomic_species.append(" ");
          atomic_species.append(sym);
          atomic_species.append(" ");
          atomic_species.append(QByteArray::number(m_masses[Z]));
          atomic_species.append(" ");
          atomic_species.append(mpp[sym]);
          atomic_species.append("\n");
      }
      atomic_species.append("\n");
      QString atomic_positions = "ATOMIC_POSITIONS angstrom\n";
      QList<Atom*> atoms = mol_->atoms();
      for (int i=0;i<atoms.size();i++) {
          Atom &a = *atoms[i];
          int Z = a.atomicNumber();
          QString sym = m_symbols[Z];
          atomic_positions.append(" ");
          atomic_positions.append(sym);
          atomic_positions.append(" ");
          atomic_positions.append(QByteArray::number(a.pos()->x()));
          atomic_positions.append(" ");
          atomic_positions.append(QByteArray::number(a.pos()->y()));
          atomic_positions.append(" ");
          atomic_positions.append(QByteArray::number(a.pos()->z()));
          atomic_positions.append("\n");
      }
      atomic_positions.append("\n");
      input.append(atomic_species);
      input.append(atomic_positions);
      input.append("K_POINTS automatic\n 20 20 20 0 0 0\n\n");

      input.append("CELL_PARAMETERS angstrom\n");
      for (int i=0;i<3;i++) {
          for (int j=0;j<3;j++) {
              input.append(QByteArray::number(mol_->OBUnitCell()->GetCellMatrix().Get(i, j)));
              input.append(" ");
          }
          input.append("\n");
      }
//      qDebug() << input;

      hide();
      QTextEdit *text = new QTextEdit;
      text->setText(input);
      text->show();
  }
}
