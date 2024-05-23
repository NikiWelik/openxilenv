/*
 * Copyright 2023 ZF Friedrichshafen AG
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef STARTSTOPXCPCALWIDGET_H
#define STARTSTOPXCPCALWIDGET_H

#include <QWidget>

#include "XcpConfigWidget.h"

namespace Ui {
class StartStopXCPCalWidget;
}

class StartStopXCPCalWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartStopXCPCalWidget(QWidget *parent = nullptr);
    ~StartStopXCPCalWidget();

private slots:
    void on_pushButtonFilter_clicked();

    void on_pushButtonRight_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    bool InOnList(QString &Name);
    void CloseDialog();
    Ui::StartStopXCPCalWidget *ui;
    static int Connection;
    int curConnection;
    XCPCFGDLG_SHEET_DATA *xcpconfig_data;
    void FillListBoxes(const char *Filter);
};

#endif // STARTSTOPXCPCALWIDGET_H
