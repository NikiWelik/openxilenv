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


#include "SaveCcpConfigDialog.h"
#include "ui_SaveCcpConfigDialog.h"

#include "FileDialog.h"
#include "StringHelpers.h"

#include <QMessageBox>

extern"C"
{
    #include "CcpControl.h"
    #include "ThrowError.h"
    #include "FileExtensions.h"
}

SaveCCPConfigDialog::SaveCCPConfigDialog(QWidget *parent) : Dialog(parent),
    ui(new Ui::SaveCCPConfigDialog)
{
    ui->setupUi(this);
    ui->radioButtonCon0->setChecked(true);
}

SaveCCPConfigDialog::~SaveCCPConfigDialog()
{
    delete ui;
}

void SaveCCPConfigDialog::accept()
{
    char fileName[MAX_PATH];
    int i;
    if (ui->lineEditBrowse->text().isEmpty())
    {
        QMessageBox msgWarnBox;
        msgWarnBox.setIcon(QMessageBox::Warning);
        msgWarnBox.setText(QString("No file selected!"));
        msgWarnBox.setInformativeText("Please select a file!");
        msgWarnBox.exec();
        return;
    }
    if (ui->radioButtonCon0->isChecked())
    {
        i = 0;
    } else if (ui->radioButtonCon1->isChecked()) {
        i = 1;
    } else if (ui->radioButtonCon2->isChecked()) {
        i = 2;
    } else if (ui->radioButtonCon3->isChecked()) {
        i = 3;
    } else {
        ThrowError(1, "Unhandled Error");
        return;
    }
    strcpy(fileName, QStringToConstChar(ui->lineEditBrowse->text()));
    SaveConfig_CCP(i, fileName);
    QDialog::accept();
}

void SaveCCPConfigDialog::on_pushButtonBrowse_clicked()
{
    ui->lineEditBrowse->setText(FileDialog::getSaveFileName(this, QString ("Save CCP file"), QString(), QString (CCP_EXT)));
}
