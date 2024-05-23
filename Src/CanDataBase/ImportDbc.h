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


#ifndef IMP_DBC_H
#define IMP_DBC_H

int CANDB_GetAllBusMembers (const char *FileName, char **MemberNames);

void CANDB_FreeMembersList (char *MemberNames);

int CANDB_Import (const char *FileName, char *TxMemberList, char *RxMemberList,
                  const char *Prefix, const char *Postfix,
                  int TransferSettingsFlag,
                  int VarianteNr,
                  int ObjectAddEquFlag,
                  int SortSigFlag,
                  int SigDTypeFlag,
                  int SigEquFlag,
                  int SigInitValueFlag,
                  int ObjectInitDataFlag,
                  int ExtendSignalNameWithObjectNameFlag);

#endif
