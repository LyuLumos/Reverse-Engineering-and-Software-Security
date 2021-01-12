#include <Windows.h>
#include <stdio.h>

typedef BOOL(*CUC_PROC_ADDR)();

int main() {
	HMODULE hMoudle = LoadLibraryA("myDll.dll");
	CUC_PROC_ADDR cuc_ptr = (CUC_PROC_ADDR)GetProcAddress(hMoudle, "cuc");
	void* cuc = GetProcAddress(hMoudle, "cuc");
	void* bj = GetProcAddress(hMoudle, "bj");
	printf("CUC's pos: %p, BJ's pos: %p\n", cuc, bj);
	cuc_ptr();
}