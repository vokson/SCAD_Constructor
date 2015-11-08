#include "stdafx.h"

#include "ScadAPIX.hxx"

//void  ApiMsg( LPCSTR Text ) {	AfxMessageBox(Text,MB_OK|MB_ICONSTOP|MB_SYSTEMMODAL);  }

void APITestReadProject( )
{
	const static UnitsAPI Un[3] = { { "m", 1 },  { "cm", 100 }, { "T", 1 } };
	ScadAPI	handle(NULL);
	LPCSTR Text;
	UINT i;
	APICode Code;

	if ( ApiCreate(&handle) != APICode_OK ) ApiMsg("Error");  //  �������� ������� API � ��������
	
	Code = ApiReadProject(handle,NULL);
	if ( Code != APICode_OK ) {  APIPhrase(handle,Code);  ApiRelease(&handle); return;  }  

	//  ����� ���� ��� ��������� �� �������, ��� � �������������� 
	for ( i=1; i<=ApiGetQuantityPhrase(handle); i++ ) {
		Text = ApiGetPhrase(handle,i);
		if ( Text ) ApiMsg(Text);
	}

	if ( ApiSetLanguage (handle,1) != APICode_OK ) ApiMsg("Error");               
	ApiSetUnits(handle,Un);               
	// ............
	Text = ApiGetProjectNameFile(handle);

	Code = ApiWriteProject(handle,Text);
	if ( Code != APICode_OK ) {  APIPhrase(handle,Code); }  
	ApiRelease(&handle);
}
