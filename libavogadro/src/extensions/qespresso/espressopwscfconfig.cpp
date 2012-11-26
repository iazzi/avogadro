#include "espressopwscfconfig.h"


#include <QWidget>
#include <QFormLayout>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QComboBox>
#include <QScrollArea>

#include <QDebug>

EspressoPWscfConfig::EspressoPWscfConfig (QObject *parent) :
    QObject(parent) {
    setupControl();
    setupSystem();
    setupElectrons();
    setupIons();
    setupCell();
    setupSpecies();
}

QComboBox *EspressoPWscfConfig::boolCombo () {
    QComboBox *ret = new QComboBox;
    ret->addItem("", "");
    ret->addItem(".true.", ".true.");
    ret->addItem(".false.", ".false.");
    return ret;
}

void EspressoPWscfConfig::setupControl () {
    QWidget *ret = new QWidget;
    QScrollArea *sa = new QScrollArea;
    sa->setFrameShape(QFrame::NoFrame);
    QFormLayout *layout = new QFormLayout;
    QWidget *editor = 0;
    editor = new QLineEdit; editor->setObjectName("calculation"); layout->addRow("calculation", editor);
    editor = new QLineEdit; editor->setObjectName("title"); layout->addRow("title", editor);
    editor = new QLineEdit; editor->setObjectName("verbosity"); layout->addRow("verbosity", editor);
    editor = new QLineEdit; editor->setObjectName("restart_mode"); layout->addRow("restart_mode", editor);
    editor = boolCombo(); editor->setObjectName("wf_collect"); layout->addRow("wf_collect", editor);
    editor = new QSpinBox; editor->setObjectName("nstep"); layout->addRow("nstep", editor);
    editor = new QSpinBox; editor->setObjectName("iprint"); layout->addRow("iprint", editor);
    editor = boolCombo(); editor->setObjectName("tstress"); layout->addRow("tstress", editor);
    editor = boolCombo(); editor->setObjectName("tprnfor"); layout->addRow("tprnfor", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("dt"); layout->addRow("dt", editor);
    editor = new QLineEdit; editor->setObjectName("outdir"); layout->addRow("outdir", editor);
    editor = new QLineEdit; editor->setObjectName("wfcdir"); layout->addRow("wfcdir", editor);
    editor = new QLineEdit; editor->setObjectName("prefix"); layout->addRow("prefix", editor);
    editor = boolCombo(); editor->setObjectName("lkpoint_dir"); layout->addRow("lkpoint_dir", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("max_seconds"); layout->addRow("max_seconds", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("etot_conv_thr"); layout->addRow("etot_conv_thr", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("forc_conv_thr"); layout->addRow("forc_conv_thr", editor);
    editor = new QLineEdit; editor->setObjectName("disk_io"); layout->addRow("disk_io", editor);
    editor = new QLineEdit; editor->setObjectName("pseudo_dir"); layout->addRow("pseudo_dir", editor);
    editor = boolCombo(); editor->setObjectName("tefield"); layout->addRow("tefield", editor);
    editor = boolCombo(); editor->setObjectName("dipfield"); layout->addRow("dipfield", editor);
    editor = boolCombo(); editor->setObjectName("lelfield"); layout->addRow("lelfield", editor);
    editor = new QSpinBox; editor->setObjectName("nberrycyc"); layout->addRow("nberrycyc", editor);
    editor = boolCombo(); editor->setObjectName("lberry"); layout->addRow("lberry", editor);
    editor = new QSpinBox; editor->setObjectName("gdir"); layout->addRow("gdir", editor);
    ret->setLayout(layout);
    sa->setWidget(ret);
    m_controlWidget = sa;
}

void EspressoPWscfConfig::setupSystem () {
    QWidget *ret = new QWidget;
    QScrollArea *sa = new QScrollArea;
    sa->setFrameShape(QFrame::NoFrame);
    QFormLayout *layout = new QFormLayout;
    QWidget *editor = 0;
    editor = new QSpinBox; editor->setObjectName("ibrav"); layout->addRow("ibrav", editor);
//    editor = new QDoubleSpinBox; editor->setObjectName("celldm(i),i=1,6"); layout->addRow("celldm(i),i=1,6", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("A"); layout->addRow("A", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("B"); layout->addRow("B", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("C"); layout->addRow("C", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("cosAB"); layout->addRow("cosAB", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("cosAC"); layout->addRow("cosAC", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("cosBC"); layout->addRow("cosBC", editor);
    editor = new QSpinBox; editor->setObjectName("nat"); layout->addRow("nat", editor);
    editor = new QSpinBox; editor->setObjectName("ntyp"); layout->addRow("ntyp", editor);
    editor = new QSpinBox; editor->setObjectName("nbnd"); layout->addRow("nbnd", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("tot_charge"); layout->addRow("tot_charge", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("tot_magnetization"); layout->addRow("tot_magnetization", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("starting_magnetization(i),i=1,ntyp"); layout->addRow("starting_magnetization(i),i=1,ntyp", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("ecutwfc"); layout->addRow("ecutwfc", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("ecutrho"); layout->addRow("ecutrho", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("ecutfock"); layout->addRow("ecutfock", editor);
    editor = new QSpinBox; editor->setObjectName("nr1,nr2,nr3"); layout->addRow("nr1,nr2,nr3", editor);
    editor = new QSpinBox; editor->setObjectName("nr1s,nr2s,nr3s"); layout->addRow("nr1s,nr2s,nr3s", editor);
    editor = boolCombo(); editor->setObjectName("nosym"); layout->addRow("nosym", editor);
    editor = boolCombo(); editor->setObjectName("nosym_evc"); layout->addRow("nosym_evc", editor);
    editor = boolCombo(); editor->setObjectName("noinv"); layout->addRow("noinv", editor);
    editor = boolCombo(); editor->setObjectName("no_t_rev"); layout->addRow("no_t_rev", editor);
    editor = boolCombo(); editor->setObjectName("force_symmorphic"); layout->addRow("force_symmorphic", editor);
    editor = boolCombo(); editor->setObjectName("use_all_frac"); layout->addRow("use_all_frac", editor);
    editor = new QLineEdit; editor->setObjectName("occupations"); layout->addRow("occupations", editor);
    editor = boolCombo(); editor->setObjectName("one_atom_occupations"); layout->addRow("one_atom_occupations", editor);
    editor = boolCombo(); editor->setObjectName("starting_spin_angle"); layout->addRow("starting_spin_angle", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("degauss"); layout->addRow("degauss", editor);
    editor = new QLineEdit; editor->setObjectName("smearing"); layout->addRow("smearing", editor);
    editor = new QSpinBox; editor->setObjectName("nspin"); layout->addRow("nspin", editor);
    editor = boolCombo(); editor->setObjectName("noncolin"); layout->addRow("noncolin", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("ecfixed"); layout->addRow("ecfixed", editor);
    editor = new QLineEdit; editor->setObjectName("input_dft"); layout->addRow("input_dft", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("exx_fraction"); layout->addRow("exx_fraction", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("screening_parameter"); layout->addRow("screening_parameter", editor);
    editor = new QLineEdit; editor->setObjectName("exxdiv_treatment"); layout->addRow("exxdiv_treatment", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("ecutvcut"); layout->addRow("ecutvcut", editor);
    editor = new QSpinBox; editor->setObjectName("nqx1,nqx2,nqx3"); layout->addRow("nqx1,nqx2,nqx3", editor);
    editor = boolCombo(); editor->setObjectName("lda_plus_u"); layout->addRow("lda_plus_u", editor);
    editor = new QSpinBox; editor->setObjectName("lda_plus_u_kind"); layout->addRow("lda_plus_u_kind", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("Hubbard_U(i),i=1,ntyp"); layout->addRow("Hubbard_U(i),i=1,ntyp", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("Hubbard_alpha(i),i=1,ntyp"); layout->addRow("Hubbard_alpha(i),i=1,ntyp", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("Hubbard_J(i,ityp)"); layout->addRow("Hubbard_J(i,ityp)", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("starting_ns_eigenvalue(m,ispin,I)"); layout->addRow("starting_ns_eigenvalue(m,ispin,I)", editor);
    editor = new QLineEdit; editor->setObjectName("U_projection_type"); layout->addRow("U_projection_type", editor);
    editor = new QSpinBox; editor->setObjectName("edir"); layout->addRow("edir", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("emaxpos"); layout->addRow("emaxpos", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("eopreg"); layout->addRow("eopreg", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("eamp"); layout->addRow("eamp", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("angle1(i),i=1,ntyp"); layout->addRow("angle1(i),i=1,ntyp", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("angle2(i),i=1,ntyp"); layout->addRow("angle2(i),i=1,ntyp", editor);
    editor = new QLineEdit; editor->setObjectName("constrained_magnetization"); layout->addRow("constrained_magnetization", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("fixed_magnetization(i),i=1,3"); layout->addRow("fixed_magnetization(i),i=1,3", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("lambda"); layout->addRow("lambda", editor);
    editor = new QSpinBox; editor->setObjectName("report"); layout->addRow("report", editor);
    editor = boolCombo(); editor->setObjectName("lspinorb"); layout->addRow("lspinorb", editor);
    editor = new QLineEdit; editor->setObjectName("assume_isolated"); layout->addRow("assume_isolated", editor);
    editor = new QLineEdit; editor->setObjectName("esm_bc"); layout->addRow("esm_bc", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("esm_w"); layout->addRow("esm_w", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("esm_efield"); layout->addRow("esm_efield", editor);
    editor = new QSpinBox; editor->setObjectName("esm_nfit"); layout->addRow("esm_nfit", editor);
    editor = boolCombo(); editor->setObjectName("london"); layout->addRow("london", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("london_s6"); layout->addRow("london_s6", editor);
    ret->setLayout(layout);
    sa->setWidget(ret);
    m_systemWidget = sa;
}

void EspressoPWscfConfig::setupElectrons () {
    QWidget *ret = new QWidget;
    QScrollArea *sa = new QScrollArea;
    sa->setFrameShape(QFrame::NoFrame);
    QFormLayout *layout = new QFormLayout;
    QWidget *editor = 0;
    editor = new QSpinBox; editor->setObjectName("electron_maxstep"); layout->addRow("electron_maxstep", editor);
    editor = boolCombo(); editor->setObjectName("scf_must_converge"); layout->addRow("scf_must_converge", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("conv_thr"); layout->addRow("conv_thr", editor);
    editor = boolCombo(); editor->setObjectName("adaptive_thr"); layout->addRow("adaptive_thr", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("conv_thr_init"); layout->addRow("conv_thr_init", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("conv_thr_multi"); layout->addRow("conv_thr_multi", editor);
    editor = new QLineEdit; editor->setObjectName("mixing_mode"); layout->addRow("mixing_mode", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("mixing_beta"); layout->addRow("mixing_beta", editor);
    editor = new QSpinBox; editor->setObjectName("mixing_ndim"); layout->addRow("mixing_ndim", editor);
    editor = new QSpinBox; editor->setObjectName("mixing_fixed_ns"); layout->addRow("mixing_fixed_ns", editor);
    editor = new QLineEdit; editor->setObjectName("diagonalization"); layout->addRow("diagonalization", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("diago_thr_init"); layout->addRow("diago_thr_init", editor);
    editor = new QSpinBox; editor->setObjectName("diago_cg_maxiter"); layout->addRow("diago_cg_maxiter", editor);
    editor = new QSpinBox; editor->setObjectName("diago_david_ndim"); layout->addRow("diago_david_ndim", editor);
    editor = boolCombo(); editor->setObjectName("diago_full_acc"); layout->addRow("diago_full_acc", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("efield"); layout->addRow("efield", editor);
    editor = new QDoubleSpinBox; editor->setObjectName("efield_cart(i),i=1,3"); layout->addRow("efield_cart(i),i=1,3", editor);
    editor = new QLineEdit; editor->setObjectName("startingpot"); layout->addRow("startingpot", editor);
    editor = new QLineEdit; editor->setObjectName("startingwfc"); layout->addRow("startingwfc", editor);
    ret->setLayout(layout);
    sa->setWidget(ret);
    m_electronsWidget = sa;
}

void EspressoPWscfConfig::setupIons () {
}

void EspressoPWscfConfig::setupCell () {
}

void EspressoPWscfConfig::setupSpecies () {
    QWidget *ret = new QWidget;
    QFormLayout *layout = new QFormLayout;
//    layout->addRow("TEST", new QLabel("TEST!"));
    ret->setLayout(layout);
    m_speciesLayout = layout;
    m_speciesWidget = ret;
}

QString EspressoPWscfConfig::controlSection () {
    QWidget *form = m_controlWidget;
    QString ret = "&CONTROL\n";
    QStringList list;
    QString entry;

    entry = form->findChild<QLineEdit*>("calculation")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  calculation = " + entry);
    entry = form->findChild<QLineEdit*>("title")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  title = " + entry);
    entry = form->findChild<QLineEdit*>("verbosity")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  verbosity = " + entry);
    entry = form->findChild<QLineEdit*>("restart_mode")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  restart_mode = " + entry);
    entry = form->findChild<QComboBox*>("wf_collect")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  wf_collect = " + entry);
    entry = form->findChild<QSpinBox*>("nstep")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nstep = " + entry);
    entry = form->findChild<QSpinBox*>("iprint")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  iprint = " + entry);
    entry = form->findChild<QComboBox*>("tstress")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  tstress = " + entry);
    entry = form->findChild<QComboBox*>("tprnfor")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  tprnfor = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("dt")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  dt = " + entry);
    entry = form->findChild<QLineEdit*>("outdir")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  outdir = " + entry);
    entry = form->findChild<QLineEdit*>("wfcdir")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  wfcdir = " + entry);
    entry = form->findChild<QLineEdit*>("prefix")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  prefix = " + entry);
    entry = form->findChild<QComboBox*>("lkpoint_dir")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lkpoint_dir = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("max_seconds")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  max_seconds = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("etot_conv_thr")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  etot_conv_thr = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("forc_conv_thr")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  forc_conv_thr = " + entry);
    entry = form->findChild<QLineEdit*>("disk_io")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  disk_io = " + entry);
    entry = form->findChild<QLineEdit*>("pseudo_dir")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  pseudo_dir = " + entry);
    entry = form->findChild<QComboBox*>("tefield")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  tefield = " + entry);
    entry = form->findChild<QComboBox*>("dipfield")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  dipfield = " + entry);
    entry = form->findChild<QComboBox*>("lelfield")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lelfield = " + entry);
    entry = form->findChild<QSpinBox*>("nberrycyc")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nberrycyc = " + entry);
    entry = form->findChild<QComboBox*>("lberry")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lberry = " + entry);
    entry = form->findChild<QSpinBox*>("gdir")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  gdir = " + entry);

    ret.append(list.join("\n"));
    ret.append("\n/\n\n");
    return ret;
}

QString EspressoPWscfConfig::systemSection () {
    QWidget *form = m_systemWidget;
    QString ret = "&SYSTEM\n";
    QStringList list;
    QString entry;

    entry = form->findChild<QSpinBox*>("ibrav")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ibrav = " + entry);
//    entry = form->findChild<QDoubleSpinBox*>("celldm(i),i=1,6")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  celldm(i),i=1,6 = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("A")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  A = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("B")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  B = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("C")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  C = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("cosAB")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  cosAB = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("cosAC")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  cosAC = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("cosBC")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  cosBC = " + entry);
    entry = form->findChild<QSpinBox*>("nat")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nat = " + entry);
    entry = form->findChild<QSpinBox*>("ntyp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ntyp = " + entry);
    entry = form->findChild<QSpinBox*>("nbnd")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nbnd = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("tot_charge")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  tot_charge = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("tot_magnetization")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  tot_magnetization = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("starting_magnetization(i),i=1,ntyp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  starting_magnetization(i),i=1,ntyp = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("ecutwfc")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ecutwfc = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("ecutrho")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ecutrho = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("ecutfock")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ecutfock = " + entry);
    entry = form->findChild<QSpinBox*>("nr1,nr2,nr3")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nr1,nr2,nr3 = " + entry);
    entry = form->findChild<QSpinBox*>("nr1s,nr2s,nr3s")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nr1s,nr2s,nr3s = " + entry);
    entry = form->findChild<QComboBox*>("nosym")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nosym = " + entry);
    entry = form->findChild<QComboBox*>("nosym_evc")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nosym_evc = " + entry);
    entry = form->findChild<QComboBox*>("noinv")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  noinv = " + entry);
    entry = form->findChild<QComboBox*>("no_t_rev")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  no_t_rev = " + entry);
    entry = form->findChild<QComboBox*>("force_symmorphic")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  force_symmorphic = " + entry);
    entry = form->findChild<QComboBox*>("use_all_frac")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  use_all_frac = " + entry);
    entry = form->findChild<QLineEdit*>("occupations")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  occupations = " + entry);
    entry = form->findChild<QComboBox*>("one_atom_occupations")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  one_atom_occupations = " + entry);
    entry = form->findChild<QComboBox*>("starting_spin_angle")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  starting_spin_angle = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("degauss")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  degauss = " + entry);
    entry = form->findChild<QLineEdit*>("smearing")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  smearing = " + entry);
    entry = form->findChild<QSpinBox*>("nspin")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nspin = " + entry);
    entry = form->findChild<QComboBox*>("noncolin")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  noncolin = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("ecfixed")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ecfixed = " + entry);
    entry = form->findChild<QLineEdit*>("input_dft")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  input_dft = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("exx_fraction")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  exx_fraction = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("screening_parameter")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  screening_parameter = " + entry);
    entry = form->findChild<QLineEdit*>("exxdiv_treatment")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  exxdiv_treatment = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("ecutvcut")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  ecutvcut = " + entry);
    entry = form->findChild<QSpinBox*>("nqx1,nqx2,nqx3")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  nqx1,nqx2,nqx3 = " + entry);
    entry = form->findChild<QComboBox*>("lda_plus_u")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lda_plus_u = " + entry);
    entry = form->findChild<QSpinBox*>("lda_plus_u_kind")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lda_plus_u_kind = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("Hubbard_U(i),i=1,ntyp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  Hubbard_U(i),i=1,ntyp = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("Hubbard_alpha(i),i=1,ntyp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  Hubbard_alpha(i),i=1,ntyp = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("Hubbard_J(i,ityp)")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  Hubbard_J(i,ityp) = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("starting_ns_eigenvalue(m,ispin,I)")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  starting_ns_eigenvalue(m,ispin,I) = " + entry);
    entry = form->findChild<QLineEdit*>("U_projection_type")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  U_projection_type = " + entry);
    entry = form->findChild<QSpinBox*>("edir")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  edir = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("emaxpos")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  emaxpos = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("eopreg")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  eopreg = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("eamp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  eamp = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("angle1(i),i=1,ntyp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  angle1(i),i=1,ntyp = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("angle2(i),i=1,ntyp")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  angle2(i),i=1,ntyp = " + entry);
    entry = form->findChild<QLineEdit*>("constrained_magnetization")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  constrained_magnetization = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("fixed_magnetization(i),i=1,3")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  fixed_magnetization(i),i=1,3 = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("lambda")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lambda = " + entry);
    entry = form->findChild<QSpinBox*>("report")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  report = " + entry);
    entry = form->findChild<QComboBox*>("lspinorb")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  lspinorb = " + entry);
    entry = form->findChild<QLineEdit*>("assume_isolated")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  assume_isolated = " + entry);
    entry = form->findChild<QLineEdit*>("esm_bc")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("  esm_bc = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("esm_w")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  esm_w = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("esm_efield")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  esm_efield = " + entry);
    entry = form->findChild<QSpinBox*>("esm_nfit")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  esm_nfit = " + entry);
    entry = form->findChild<QComboBox*>("london")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  london = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("london_s6")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("  london_s6 = " + entry);

    ret.append(list.join("\n"));
    ret.append("\n/\n\n");
    return ret;
}

QString EspressoPWscfConfig::electronsSection () {
    QWidget *form = m_electronsWidget;
    QString ret = "&ELECTRONS\n";
    QStringList list;
    QString entry;

    entry = form->findChild<QSpinBox*>("electron_maxstep")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("electron_maxstep = " + entry);
    entry = form->findChild<QComboBox*>("scf_must_converge")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("scf_must_converge = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("conv_thr")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("conv_thr = " + entry);
    entry = form->findChild<QComboBox*>("adaptive_thr")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("adaptive_thr = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("conv_thr_init")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("conv_thr_init = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("conv_thr_multi")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("conv_thr_multi = " + entry);
    entry = form->findChild<QLineEdit*>("mixing_mode")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("mixing_mode = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("mixing_beta")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("mixing_beta = " + entry);
    entry = form->findChild<QSpinBox*>("mixing_ndim")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("mixing_ndim = " + entry);
    entry = form->findChild<QSpinBox*>("mixing_fixed_ns")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("mixing_fixed_ns = " + entry);
    entry = form->findChild<QLineEdit*>("diagonalization")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("diagonalization = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("diago_thr_init")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("diago_thr_init = " + entry);
    entry = form->findChild<QSpinBox*>("diago_cg_maxiter")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("diago_cg_maxiter = " + entry);
    entry = form->findChild<QSpinBox*>("diago_david_ndim")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("diago_david_ndim = " + entry);
    entry = form->findChild<QComboBox*>("diago_full_acc")->currentText(); if (!entry.isEmpty() && entry!="\"\"") list << ("diago_full_acc = " + entry);
    entry = form->findChild<QDoubleSpinBox*>("efield")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("efield" + entry);
    entry = form->findChild<QDoubleSpinBox*>("efield_cart(i),i=1,3")->cleanText(); if (!entry.isEmpty() && entry!="\"\"") list << ("efield_cart(i),i=1,3 = " + entry);
    entry = form->findChild<QLineEdit*>("startingpot")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("startingpot = " + entry);
    entry = form->findChild<QLineEdit*>("startingwfc")->text().prepend('"').append('"'); if (!entry.isEmpty() && entry!="\"\"") list << ("startingwfc = " + entry);

    ret.append(list.join("\n"));
    ret.append("\n/\n\n");
    return ret;
}

QString EspressoPWscfConfig::ionsSection () {
    QWidget *form = m_controlWidget;
    QString ret = "&IONS\n";
    QStringList list;


    ret.append(list.join("\n"));
    ret.append("\n/\n\n");
    return ret;
}

QString EspressoPWscfConfig::cellSection () {
    QWidget *form = m_controlWidget;
    QString ret = "&CELL\n";
    QStringList list;


    ret.append(list.join("\n"));
    ret.append("\n/\n\n");
    return ret;
}

QMap<QString, QString> EspressoPWscfConfig::pseudopotentials () {
    QMap<QString, QString> ret;
    QList<QComboBox*> l = m_speciesWidget->findChildren<QComboBox*>();
    for (int i=0;i<l.count();i++) {
//        qDebug() << l.at(i)->objectName() << l.at(i)->currentText();
        ret.insert(l.at(i)->objectName(), l.at(i)->currentText());
    }
    return ret;
}

void EspressoPWscfConfig::setCell (int ibrav, double a, double b, double c, double cosAB, double cosBC, double cosAC) {
    m_systemWidget->findChild<QSpinBox*>("ibrav")->setValue(ibrav);
    m_systemWidget->findChild<QDoubleSpinBox*>("A")->setValue(a);
    m_systemWidget->findChild<QDoubleSpinBox*>("B")->setValue(b);
    m_systemWidget->findChild<QDoubleSpinBox*>("C")->setValue(c);
    m_systemWidget->findChild<QDoubleSpinBox*>("cosAB")->setValue(cosAB);
    m_systemWidget->findChild<QDoubleSpinBox*>("cosBC")->setValue(cosBC);
    m_systemWidget->findChild<QDoubleSpinBox*>("cosAC")->setValue(cosAC);
}

void EspressoPWscfConfig::setSpecies (QStringList snames) {
    QDir dir("/home/iazzi/projects/espresso-5.0/upf_files");

//    QLayoutItem *child;
//    for (int i=0;i<m_speciesLayout->rowCount();i++) {
//        child = m_speciesLayout->itemAt(i, QFormLayout::LabelRole);
//        if (child) m_speciesLayout->removeItem(child);
//        child = m_speciesLayout->itemAt(i, QFormLayout::FieldRole);
//        if (child) m_speciesLayout->removeItem(child);
//        child = m_speciesLayout->itemAt(i, QFormLayout::SpanningRole);
//        if (child) m_speciesLayout->removeItem(child);
//    }
//    qDebug() << m_speciesLayout->rowCount();
//    qDebug() << m_speciesLayout->count();

//    QFormLayout *layout = new QFormLayout;
//    if (m_speciesLayout) delete m_speciesLayout;
//    m_speciesWidget->setLayout(layout);
//    m_speciesLayout = layout;
//    qDebug() << "species:" << snames;
    for (int i=0;i<snames.count();i++) {
        QString sym = snames[i];
        if (m_speciesWidget->findChild<QComboBox*>(sym)) continue;
        QComboBox *editor = new QComboBox;
        editor->setEditable(false);
        editor->addItems(dir.entryList(QStringList(sym+".*")));
//        qDebug() << dir.entryList();
        editor->setObjectName(sym);
        m_speciesLayout->addRow(sym, editor);
    }
}

#include "espressopwscfconfig.moc"
