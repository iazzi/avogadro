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
  GNU General Public icense for more details.
 ***********************************************************************/

#ifndef ESPRESSODIALOG_H
#define ESPRESSODIALOG_H

#include <QtGui>

#include "espressopwscfconfig.h"

namespace Avogadro {
  class Molecule;
}

namespace Espresso {
  class EspressoExtension;

  class EspressoPWscfDialog : public QDialog {
    Q_OBJECT

      EspressoPWscfConfig *m_config;

      int ntyp;
      int nat;

      int ibrav;
      double a, b, c;
      double cosAB, cosAC, cosBC;

      QWidget *m_controlWidget;
      QWidget *m_systemWidget;
      QWidget *m_electronsWidget;
      QWidget *m_ionsWidget;
      QWidget *m_cellWidget;

      std::vector<double> m_masses;
      std::vector<QString> m_symbols;
      std::vector<QString> m_pseudopotentials;

      Avogadro::Molecule *mol_;

      QList<int> species;

      void readMolecule ();
  public:
    explicit EspressoPWscfDialog (QWidget *parent,
                                  EspressoExtension *ext);

    virtual ~EspressoPWscfDialog () {};

  public slots:
    // Reset the GUI if there is no molecule loaded
//    void reset ();
    // Count the number of hydrogens in the passed molecule and update
    // the GUI
//    void update (Avogadro::Molecule *mol);
      void run (Avogadro::Molecule *mol);
      void write ();

  private:
    // Pointer to the extension
    EspressoExtension *m_ext;
  };
}

#endif
