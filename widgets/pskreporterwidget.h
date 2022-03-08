#ifndef PSKREPORTERWIDGET_H
#define PSKREPORTERWIDGET_H

#include <QWidget>
#include "logbook/logbook.h"

class Configuration;
class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;
class LogBook;

namespace Ui {
class PSKReporterWidget;
}

class PSKReporterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PSKReporterWidget(QWidget *parent = nullptr, Configuration *cfg = nullptr, LogBook *log = nullptr);
    ~PSKReporterWidget();
    void setFont (QFont f);

public slots:
    void refresh(bool init = false);
    void updateTable(QString data);
    void scrollToBottom();

private:
    Ui::PSKReporterWidget *ui;
    QNetworkAccessManager * networkManager;
    Configuration * m_config;
    LogBook * m_logBook;


private slots:
    void responseHandler(QNetworkReply * reply);

};

#endif // PSKREPORTERWIDGET_H
