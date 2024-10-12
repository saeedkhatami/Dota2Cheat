#pragma once
#include "CNetworkMessages.h"

class CNetworkGameClient;
class INetChannel;

struct INetworkMessageProcessingPreFilter {
	virtual bool Filter(VClass* msg, INetChannel* netchan) = 0;
};

class INetChannel : public VClass
{
public:
	bool SendNetMessage(NetMessageHandle_t* messageHandle, google::protobuf::Message* msg, NetChannelBufType_t type) {
		return CallVFunc<69>(messageHandle, msg, type);
	}

	void StartRegisteringMessageHandlers() {
		GetVFunc(58)();
	}

	void FinishRegisteringMessageHandlers() {
		GetVFunc(59)();
	}

	void RegisterAbstractMessageHandler(void* handlerBuffer, CUtlAbstractDelegate* handler, int flag2, CNetworkSerializerPB* pbSerializer, int flag3) {
		GetVFunc(60)(handlerBuffer, handler, flag2, pbSerializer, flag3);
	}

	void InstallMessageFilter(INetworkMessageProcessingPreFilter* filter) {
		GetVFunc(67)(filter);
	}

	void UninstallMessageFilter(INetworkMessageProcessingPreFilter* filter) {
		GetVFunc(68)(filter);
	}
};