#pragma once
#include "clsUser.h"
#include "clsBankClient.h"
static clsUser CurrentUser = clsUser::Find("", "");
static clsBankClient FromClient = clsBankClient::Find("", "");
static clsBankClient ToClient = clsBankClient::Find("", "");
static double Amount1 = 0;