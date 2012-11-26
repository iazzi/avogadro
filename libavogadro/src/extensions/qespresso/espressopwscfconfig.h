#ifndef ESPRESSOPWSCFCONFIG_H
#define ESPRESSOPWSCFCONFIG_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>
#include <QtGui>

class EspressoPWscfConfig : public QObject {
    Q_OBJECT

    void setupControl ();
    void setupSystem ();
    void setupElectrons ();
    void setupIons ();
    void setupCell ();

    void setupSpecies ();

    QWidget *m_controlWidget;
    QWidget *m_systemWidget;
    QWidget *m_electronsWidget;
    QWidget *m_ionsWidget;
    QWidget *m_cellWidget;

    QWidget *m_speciesWidget;
    QWidget *m_kPointsWidget;

    QFormLayout *m_speciesLayout;

    QComboBox *boolCombo ();
public:
    explicit EspressoPWscfConfig (QObject *parent = 0);

    QString controlSection ();
    QString systemSection ();
    QString electronsSection ();
    QString ionsSection ();
    QString cellSection ();

    QMap<QString, QString> pseudopotentials();

    QWidget *controlWidget () { return m_controlWidget; }
    QWidget *systemWidget () { return m_systemWidget; }
    QWidget *electronsWidget () { return m_electronsWidget; }
    QWidget *ionsWidget () { return m_ionsWidget; }


    QWidget *speciesWidget () { return m_speciesWidget; }
    QWidget *kPointsWidget () { return m_kPointsWidget; }

    void setCell (int ibrav, double a, double b, double c, double cosAB, double cosBC, double cosAC);
    void setSpecies (QStringList snames);
signals:
    
public slots:
};

#endif // ESPRESSOPWSCFCONFIG_H
