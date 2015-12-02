#pragma once

#include "../include/ApiStruct.h"

#ifdef __cplusplus
extern "C" {
#endif

void* X_LoadLib(char* libPath);
char* X_GetLastError();
void* X_GetFunction(void* lib, char* ProcName = "XRequest");
void X_FreeLib(void* lib);

ApiType X_GetApiType(void* pFun);
char* X_GetApiVersion(void* pFun);
char* X_GetApiName(void* pFun);

void* X_Create(void* pFun);
void X_Register(void* pFun, void* pApi, void* pCallback, void* pClass);

void X_Connect(void* pFun, void* pApi, char* szPath, ServerInfoField* pServerInfo, UserInfoField* pUserInfo, int count);
void X_Disconnect(void* pFun, void* pApi);

void X_Subscribe(void* pFun, void* pApi, char* szInstrument, char* szExchange);
void X_Unsubscribe(void* pFun, void* pApi, char* szInstrument, char* szExchange);
void X_SubscribeQuote(void* pFun, void* pApi, char* szInstrument, char* szExchange);
void X_UnsubscribeQuote(void* pFun, void* pApi, char* szInstrument, char* szExchange);

void X_ReqQuery(void* pFun, void* pApi, QueryType type, ReqQueryField* query);

char* X_SendOrder(void* pFun, void* pApi, OrderField* pOrder, int count, char* pOut);
char* X_CancelOrder(void* pFun, void* pApi, OrderIDType* pIn, int count, char* pOut);

char* X_SendQuote(void* pFun, void* pApi, QuoteField* pQuote, int count, char* pOut);
char* X_CancelQuote(void* pFun, void* pApi, OrderIDType* pIn, int count, char* pOut);

#ifdef __cplusplus
}
#endif
