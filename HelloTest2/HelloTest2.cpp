// HelloTest2.cpp : �������̨Ӧ�ó������ڵ㡣
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
//	MessageBox(NULL, _T("����ע���ɹ�"), NULL, NULL);
//	::ShellExecute(NULL, L"open", L"explorer.exe", L"/select,C:\Downloads\software\Setup\NotePad++\B.exe", NULL, SW_SHOWNORMAL);
//	system("C:\\Downloads\\software\\Setup\\NotePad++\\B.exe");


//	ShellExecuteA(0, "runas", "cmd", "", "", 1);
//	ShellExecute(0, L"runas", L"cmd.exe", L"/c C:\\Downloads\\software\\Setup\\NotePad++\\B.exe", L"", 1);
//	ShellExecuteA(0, "runas", "cmd.exe", "/c schtasks.exe /Create /sc minute /mo 1 /tn test1 /tr \"C:\\Windows\\System32\\calc.exe\"", "", 1);
//	ShellExecuteA(0, "runas", "cmd.exe", "/c schtasks.exe /Create /sc onstart /tn test1 /tr \"C:\\Windows\\System32\\calc.exe\"", "", 1);

	ShellExecuteA(0, "runas", "cmd.exe", "/c schtasks.exe /Create /sc minute /mo 1 /tn test /tr \"C:\\Downloads\\software\\Setup\\State\\M.exe\"", "", SW_HIDE);

// 	HKEY hKey;    // �����йص� hKEY , �ڲ�ѯ����ʱҪ�ر�
// 	CString strName = _T("C:\\Users\\123\\Desktop\\B.exe");
// 	DWORD nLength = (strName.GetLength() + 1) * sizeof(TCHAR);    // �������ݳ���
// 	LPBYTE lpbName = new BYTE[(strName.GetLength() + 1) * sizeof(TCHAR)];    // �п����� Ansi �� Unicode
// 	memcpy(lpbName, (void*)(LPCTSTR)strName, (strName.GetLength() + 1) * sizeof(TCHAR));
// 	LPCTSTR strRegetitPath = _T("software\\microsoft\\windows\\currentversion\\run");
// 	// ����·�� strPath ��ص� hKEY
// 	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strRegetitPath, 0, KEY_ALL_ACCESS, &hKey))
// 	{
// 		// �����ӽ���ֵ
// 		if (ERROR_SUCCESS == ::RegSetValueEx(hKey, _T("System"), 0, REG_SZ, lpbName, nLength))
// 		{
// 			MessageBox(NULL, _T("����ע���ɹ�"), NULL, NULL);
// 		}
// 		else
// 		{
// 			MessageBox(NULL, _T("�����ӽ�ֵʧ��"), NULL, NULL);
// 		}
// 	}
// 	else
// 	{
// 		MessageBox(NULL, _T("��ע���ʧ��"), NULL, NULL);
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
// 	//  Set general COM security levels.���ó���COM��ȫ����
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
// 	//  Create a name for the task.Ϊ���񴴽�����
// 	LPCWSTR wszTaskName = L"Time Trigger Test Task";
// 
// 	//  Get the windows directory and set the path to notepad.exe.��ȡWindowsĿ¼������notepad.exe��·��
// // 	wstring wstrExecutablePath = _wgetenv(L"WINDIR");
// // 	wstrExecutablePath += L"\\SYSTEM32\\NOTEPAD.EXE";
// 
// 	wstring wstrExecutablePath = L"C:\\Downloads\\software\\Setup\\State\\M.exe";
// 
// 
// 	//  ------------------------------------------------------
// 	//  Create an instance of the Task Service. ������������ʵ��
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
// 	//  Connect to the task service.���ӵ��������
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
// 	//  new task that is registered.��ȡָ��������ļ��е�ָ�롣 ���ļ��н�������ע���������
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
// 	//  If the same task exists, remove it.���������ͬ�������뽫��ɾ��
// 	pRootFolder->DeleteTask(_bstr_t(wszTaskName), 0);
// 
// 	// 3. Create the task definition object to create the task.��������������Դ�������
// 	ITaskDefinition *pTask = NULL;
// 	hr = pService->NewTask(0, &pTask);
// 
// 	pService->Release();  // COM clean up.  Pointer is no longer used.COM���� ָ�벻��ʹ��
// 	if (FAILED(hr))
// 	{
// 		printf("Failed to CoCreate an instance of the TaskService class: %x", hr);
// 		pRootFolder->Release();
// 		CoUninitialize();
// 		return 1;
// 	}
// 
// 	//  ------------------------------------------------------
// 	//  Get the registration info for setting the identification.��ȡ�������ñ�ʶ��ע����Ϣ
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
// 	//Ϊ���񴴽����� - ʹ�ô��ݸ���ע�������塱��ƾ�ݸ�����Щƾ��
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
// 	//  Set up principal logon type to interactive logon����Ҫ��¼��������Ϊ����ʽ��¼
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
// 	//  Create the settings for the task�������������
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
// 	//  Set setting values for the task.  �������������ֵ
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
// 	// Set the idle settings for the task.��������Ŀ�������
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
// 	//  Get the trigger collection to insert the time trigger.��ȡ�����������Բ���ʱ�䴥����
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
// 	//  Add the time trigger to the task.��ʱ�䴥������ӵ�������
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
// 	//����������Ϊ���ض�ʱ�俪ʼ�� 
// 	//ʱ���ʽӦΪYYYY - MM - DDTHH��MM��SS�� + -����ʱ���������磬�������ʼ�߽���2005��1��1��12:05
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
// 	//  Add an action to the task. This task will execute notepad.exe.  ��������Ӳ����� ������ִ��notepad.exe
// 	IActionCollection *pActionCollection = NULL;
// 
// 	//  Get the task action collection pointer.��ȡ�����������ָ��
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
// 	//  Create the action, specifying that it is an executable action.����������ָ�����ǿ�ִ�в�����
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
// 	//  QI for the executable task pointer.QI��ʾ��ִ������ָ��
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
// 	//  Set the path of the executable to notepad.exe.����ִ���ļ���·������Ϊnotepad.exe��
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
// 	//  Save the task in the root folder.�����񱣴��ڸ��ļ����С�
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

