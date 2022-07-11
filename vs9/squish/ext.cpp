#include <stdio.h>
#include <float.h>
#include "squish.h"

using namespace squish;

extern "C" 
{
	__declspec(dllexport) void __cdecl Compress2(u8 const* rgba, void* block, int flags, float* metric = 0) 
	{
		const int DEFAULT_CW = 0x9001F;
		unsigned int control_word_x87;

		// Not sure why, but sometimes CW can just reset to something we didn't expect.
		// Make sure to apply CW that the tool needs
		control_word_x87 = _control87(0, 0);
		control_word_x87 = _control87(DEFAULT_CW, MCW_EM);

		Compress( rgba, block, flags, metric );
	}	

/* EXE variant
	int main()
	{
		u8 CC[64] = {126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 126, 127, 126, 255, 127, 125, 127, 255};
		int block[2];

		//control_word_x87 = _control87(MCW_EM - _EM_INVALID, MCW_EM); This is what likely happend
		Compress(&CC[0], &block[0], 257, 0);

		return 1;
	}
*/
}

