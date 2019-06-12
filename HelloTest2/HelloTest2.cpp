// HelloTest2.cpp : 定义控制台应用程序的入口点。
//

#define _WIN32_DCOM

#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>
#include <atlstr.h>

#include <iostream>
#include <stdio.h>
#include <comdef.h>
#include <wincred.h>
//  Include the task header file.
#include <taskschd.h>
#pragma comment(lib, "taskschd.lib")
#pragma comment(lib, "comsupp.lib")
#pragma comment(lib, "credui.lib")

using namespace std;

int main()
{
//	printf("orz orz orz orz\n");
//	MessageBox(NULL, _T("更新注册表成功"), NULL, NULL);
//	::ShellExecute(NULL, L"open", L"explorer.exe", L"/select,C:\Downloads\software\Setup\NotePad++\B.exe", NULL, SW_SHOWNORMAL);
//	system("C:\\Downloads\\software\\Setup\\NotePad++\\B.exe");


//	ShellExecuteA(0, "runas", "cmd", "", "", 1);
//	ShellExecute(0, L"runas", L"cmd.exe", L"/c C:\\Downloads\\software\\Setup\\NotePad++\\B.exe", L"", 1);
//	ShellExecuteA(0, "runas", "cmd.exe", "/c schtasks.exe /Create /sc minute /mo 1 /tn test1 /tr \"C:\\Windows\\System32\\calc.exe\"", "", 1);
//	ShellExecuteA(0, "runas", "cmd.exe", "/c schtasks.exe /Create /sc onstart /tn test1 /tr \"C:\\Windows\\System32\\calc.exe\"", "", 1);

	ShellExecuteA(0, "runas", "cmd.exe", "/c schtasks.exe /Create /sc minute /mo 1 /tn test /tr \"C:\\Downloads\\software\\Setup\\State\\M.exe\"", "", SW_HIDE);

// 	HKEY hKey;    // 定义有关的 hKEY , 在查询结束时要关闭
// 	CString strName = _T("C:\\Users\\123\\Desktop\\B.exe");
// 	DWORD nLength = (strName.GetLength() + 1) * sizeof(TCHAR);    // 定义数据长度
// 	LPBYTE lpbName = new BYTE[(strName.GetLength() + 1) * sizeof(TCHAR)];    // 有可能是 Ansi 或 Unicode
// 	memcpy(lpbName, (void*)(LPCTSTR)strName, (strName.GetLength() + 1) * sizeof(TCHAR));
// 	LPCTSTR strRegetitPath = _T("software\\microsoft\\windows\\currentversion\\run");
// 	// 打开与路径 strPath 相关的 hKEY
// 	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strRegetitPath, 0, KEY_ALL_ACCESS, &hKey))
// 	{
// 		// 设置子健的值
// 		if (ERROR_SUCCESS == ::RegSetValueEx(hKey, _T("System"), 0, REG_SZ, lpbName, nLength))
// 		{
// 			MessageBox(NULL, _T("更新注册表成功"), NULL, NULL);
// 		}
// 		else
// 		{
// 			MessageBox(NULL, _T("设置子健值失败"), NULL, NULL);
// 		}
// 	}
// 	else
// 	{
// 		MessageBox(NULL, _T("打开注册表失败"), NULL, NULL);
// 	}
// 	::RegCloseKey(hKey);
// 


// 	//  Initialize COM.
// 	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCoInitializeEx failed: %x", hr);
// 		return 1;
// 	}
// 
// 	//  Set general COM security levels.设置常规COM安全级别
// 	hr = CoInitializeSecurity(
// 		NULL,
// 		-1,
// 		NULL,
// 		NULL,
// 		RPC_C_AUTHN_LEVEL_PKT_PRIVACY,
// 		RPC_C_IMP_LEVEL_IMPERSONATE,
// 		NULL,
// 		0,
// 		NULL);
// 
// 	if (FAILED(hr))
// 	{
// 		printf("\nCoInitializeSecurity failed: %x", hr);
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Create a name for the task.为任务创建名称
// 	LPCWSTR wszTaskName = L"Time Trigger Test Task";
// 
// 	//  Get the windows directory and set the path to notepad.exe.获取Windows目录并设置notepad.exe的路径
// // 	wstring wstrExecutablePath = _wgetenv(L"WINDIR");
// // 	wstrExecutablePath += L"\\SYSTEM32\\NOTEPAD.EXE";
// 
// 	wstring wstrExecutablePath = L"C:\\Downloads\\software\\Setup\\State\\M.exe";
// 
// 
// 	//  ------------------------------------------------------
// 	//  Create an instance of the Task Service. 创建任务服务的实例
// 	ITaskService *pService = NULL;
// 	hr = CoCreateInstance(CLSID_TaskScheduler,
// 		NULL,
// 		CLSCTX_INPROC_SERVER,
// 		IID_ITaskService,
// 		(void**)&pService);
// 	if (FAILED(hr))
// 	{
// 		printf("Failed to create an instance of ITaskService: %x", hr);
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  Connect to the task service.连接到任务服务
// 	hr = pService->Connect(_variant_t(), _variant_t(),
// 		_variant_t(), _variant_t());
// 	if (FAILED(hr))
// 	{
// 		printf("ITaskService::Connect failed: %x", hr);
// 		pService->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Get the pointer to the root task folder.  This folder will hold the
// 	//  new task that is registered.获取指向根任务文件夹的指针。 此文件夹将保留已注册的新任务
// 	ITaskFolder *pRootFolder = NULL;
// 	hr = pService->GetFolder(_bstr_t(L"\\"), &pRootFolder);
// 	if (FAILED(hr))
// 	{
// 		printf("Cannot get Root folder pointer: %x", hr);
// 		pService->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  If the same task exists, remove it.如果存在相同的任务，请将其删除
// 	pRootFolder->DeleteTask(_bstr_t(wszTaskName), 0);
// 
// 	// 3. Create the task definition object to create the task.创建任务定义对象以创建任务
// 	ITaskDefinition *pTask = NULL;
// 	hr = pService->NewTask(0, &pTask);
// 
// 	pService->Release();  // COM clean up.  Pointer is no longer used.COM清理。 指针不再使用
// 	if (FAILED(hr))
// 	{
// 		printf("Failed to CoCreate an instance of the TaskService class: %x", hr);
// 		pRootFolder->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Get the registration info for setting the identification.获取用于设置标识的注册信息
// 	IRegistrationInfo *pRegInfo = NULL;
// 	hr = pTask->get_RegistrationInfo(&pRegInfo);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot get identification pointer: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	hr = pRegInfo->put_Author(L"Author Name");
// 	pRegInfo->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot put identification info: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Create the principal for the task - these credentials
// 	//  are overwritten with the credentials passed to RegisterTaskDefinition
// 	//为任务创建主体 - 使用传递给“注册任务定义”的凭据覆盖这些凭据
// 	IPrincipal *pPrincipal = NULL;
// 	hr = pTask->get_Principal(&pPrincipal);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot get principal pointer: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  Set up principal logon type to interactive logon将主要登录类型设置为交互式登录
// 	hr = pPrincipal->put_LogonType(TASK_LOGON_INTERACTIVE_TOKEN);
// 	pPrincipal->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot put principal info: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Create the settings for the task创建任务的设置
// 	ITaskSettings *pSettings = NULL;
// 	hr = pTask->get_Settings(&pSettings);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot get settings pointer: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  Set setting values for the task.  设置任务的设置值
// 	hr = pSettings->put_StartWhenAvailable(VARIANT_TRUE);
// 	pSettings->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot put setting information: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	// Set the idle settings for the task.设置任务的空闲设置
// 	IIdleSettings *pIdleSettings = NULL;
// 	hr = pSettings->get_IdleSettings(&pIdleSettings);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot get idle setting information: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	hr = pIdleSettings->put_WaitTimeout(L"PT5M");
// 	pIdleSettings->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot put idle setting information: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 
// 	//  ------------------------------------------------------
// 	//  Get the trigger collection to insert the time trigger.获取触发器集合以插入时间触发器
// 	ITriggerCollection *pTriggerCollection = NULL;
// 	hr = pTask->get_Triggers(&pTriggerCollection);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot get trigger collection: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  Add the time trigger to the task.将时间触发器添加到任务中
// 	ITrigger *pTrigger = NULL;
// 	hr = pTriggerCollection->Create(TASK_TRIGGER_TIME, &pTrigger);
// 	pTriggerCollection->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot create trigger: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	ITimeTrigger *pTimeTrigger = NULL;
// 	hr = pTrigger->QueryInterface(
// 		IID_ITimeTrigger, (void**)&pTimeTrigger);
// 	pTrigger->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nQueryInterface call failed for ITimeTrigger: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	hr = pTimeTrigger->put_Id(_bstr_t(L"Trigger1"));
// 	if (FAILED(hr))
// 		printf("\nCannot put trigger ID: %x", hr);
// 
// 	hr = pTimeTrigger->put_EndBoundary(_bstr_t(L"2020-05-02T08:00:00"));
// 	if (FAILED(hr))
// 		printf("\nCannot put end boundary on trigger: %x", hr);
// 
// 	//  Set the task to start at a certain time. The time 
// 	//  format should be YYYY-MM-DDTHH:MM:SS(+-)(timezone).
// 	//  For example, the start boundary below
// 	//  is January 1st 2005 at 12:05
// 	//将任务设置为在特定时间开始。 
// 	//时间格式应为YYYY - MM - DDTHH：MM：SS（ + -）（时区）。例如，下面的起始边界是2005年1月1日12:05
// 	hr = pTimeTrigger->put_StartBoundary(_bstr_t(L"2019-06-11T18:09:00"));
// 	pTimeTrigger->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot add start boundary to trigger: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 
// 	//  ------------------------------------------------------
// 	//  Add an action to the task. This task will execute notepad.exe.  向任务添加操作。 此任务将执行notepad.exe
// 	IActionCollection *pActionCollection = NULL;
// 
// 	//  Get the task action collection pointer.获取任务操作集合指针
// 	hr = pTask->get_Actions(&pActionCollection);
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot get Task collection pointer: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  Create the action, specifying that it is an executable action.创建操作，指定它是可执行操作。
// 	IAction *pAction = NULL;
// 	hr = pActionCollection->Create(TASK_ACTION_EXEC, &pAction);
// 	pActionCollection->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot create the action: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	IExecAction *pExecAction = NULL;
// 	//  QI for the executable task pointer.QI表示可执行任务指针
// 	hr = pAction->QueryInterface(
// 		IID_IExecAction, (void**)&pExecAction);
// 	pAction->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nQueryInterface call failed for IExecAction: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  Set the path of the executable to notepad.exe.将可执行文件的路径设置为notepad.exe。
// 	hr = pExecAction->put_Path(_bstr_t(wstrExecutablePath.c_str()));
// 	pExecAction->Release();
// 	if (FAILED(hr))
// 	{
// 		printf("\nCannot put action path: %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Save the task in the root folder.将任务保存在根文件夹中。
// 	IRegisteredTask *pRegisteredTask = NULL;
// 	hr = pRootFolder->RegisterTaskDefinition(
// 		_bstr_t(wszTaskName),
// 		pTask,
// 		TASK_CREATE_OR_UPDATE,
// 		_variant_t(),
// 		_variant_t(),
// 		TASK_LOGON_INTERACTIVE_TOKEN,
// 		_variant_t(L""),
// 		&pRegisteredTask);
// 	if (FAILED(hr))
// 	{
// 		printf("\nError saving the Task : %x", hr);
// 		pRootFolder->Release();
// 		pTask->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	printf("\n Success! Task successfully registered. ");
// 
// 	//  Clean up.
// 	pRootFolder->Release();
// 	pTask->Release();
// 	pRegisteredTask->Release();
// 	CoUninitialize();



 	system("pause");
// 	
//     return 0;
}

