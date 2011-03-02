#include <s3e.h>
#include <IwGx.h>

//-----------------------------------------------------------------------------
// Main global function
//-----------------------------------------------------------------------------
int main()
{
	IwGxInit();
	IwResManagerInit();

	IwGxSetColClear(0xff, 0xff, 0xff, 0xff);
	IwGxPrintSetColour(128, 128, 128);


	while (1)
	{
		s3eDeviceYield(0);
		s3eKeyboardUpdate();
		s3ePointerUpdate();

		bool result = true;
		if	(
			(result == false) ||
			(s3eKeyboardGetState(s3eKeyEsc) & S3E_KEY_STATE_DOWN) ||
			(s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_DOWN) ||
			(s3eDeviceCheckQuitRequest())
			)
			break;

		IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
		IwGxFlush();
		IwGxSwapBuffers();
	}

	IwResManagerTerminate();
	IwGxTerminate();
	return 0;
}