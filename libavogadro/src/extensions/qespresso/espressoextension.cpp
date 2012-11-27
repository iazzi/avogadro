/**********************************************************************
  EspressoPWScfExtension

  Copyright (C) 2010 David C. Lonie

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.openmolecules.net/>

  Avogadro is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Avogadro is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
 **********************************************************************/

#include "espressoextension.h"
#include "espressopwscfdialog.h"

#include <avogadro/molecule.h>

#include <QtGui/QAction>

#include "espressopwscfdialog.h"

#include <QDebug>

using namespace Avogadro;

namespace Espresso {

  EspressoExtension::EspressoExtension (QObject *parent)
    : Extension(parent),
      m_dialog(0),
      m_molecule(0) {
    QAction *action = new QAction(this);
    action->setText(tr("PWscf"));
    m_actions.append(action);
  }

  QList<QAction *> EspressoExtension::actions () const {
    return m_actions;
  }

  QString EspressoExtension::menuPath (QAction *) const {
    return tr("E&xtensions") + '>' + tr("&QUANTUM Espresso");
  }

  void EspressoExtension::setMolecule (Molecule *mol) {
    // Has the molecule really changed?
    if (mol != m_molecule) {
      // Disconnect old molecule if it exists
      if (m_molecule) m_molecule->disconnect(this);
      // Update cached pointer
      m_molecule = mol;
      // Connect new molecule if it exists
      if (m_molecule) {
        connect(m_molecule, SIGNAL(atomAdded(Atom*)),
                this, SLOT(moleculeUpdated()));
        connect(m_molecule, SIGNAL(atomRemoved(Atom*)),
                this, SLOT(moleculeUpdated()));
        connect(m_molecule, SIGNAL(atomUpdated(Atom*)),
                this, SLOT(moleculeUpdated()));
      }
    }

    // If we haven't created the dialog yet, don't try to update it.
    if (!m_dialog) {
      return;
    }

    moleculeUpdated();
  }

  void EspressoExtension::moleculeUpdated () {
    // Emit appropriate signal depending on whether the molecule
    // exists or not
//    if (m_molecule) {
//      emit updateExtension(m_molecule);
//    } else {
//      emit resetExtension();
//    }
  }

  QUndoCommand* EspressoExtension::performAction (QAction *, GLWidget *) {
    if (!m_dialog) {
      m_dialog = new EspressoPWscfDialog(qobject_cast<QWidget*>(parent()), this);
      // Initialize the dialog
//      moleculeUpdated();
    }

    m_dialog->run(m_molecule);
    return NULL;
  }
}

Q_EXPORT_PLUGIN2(espressoextension, Espresso::EspressoExtensionFactory)
