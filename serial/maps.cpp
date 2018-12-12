#include "maps.h"
#include "ui_maps.h"
#include <QMessageBox>
#include "homelayout.h"
#include "mainwindow.h"

Maps::Maps(QWidget *parent) :
    QWidget(parent),
    m_view(new QWebEngineView(this)),
    ui(new Ui::Maps)
{
    ui->setupUi(this);
    this->setGeometry(300,50,800,600);

    //setCentralWidget(m_view);

    QWebEnginePage *page = m_view->page();

    connect(page, &QWebEnginePage::featurePermissionRequested,
            [this, page](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {
        if (feature != QWebEnginePage::Geolocation)
            return;

        QMessageBox msgBox(this);
        msgBox.setText(tr("%1 wants to know your location").arg(securityOrigin.host()));
        msgBox.setInformativeText(tr("Do you want to send your current location to this website?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);

        if (msgBox.exec() == QMessageBox::Yes) {
            page->setFeaturePermission(
                securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
        } else {
            page->setFeaturePermission(
                securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
        }
    });

    page->load(QUrl(QStringLiteral("https://maps.google.com")));
}

Maps::~Maps()
{
    delete ui;
}

void Maps::on_pushButtonHome_clicked()
{
    homeLayout *homeUI = new homeLayout;
    hide();
    homeUI->show();
}
