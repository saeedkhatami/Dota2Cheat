// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dota_client_enums.proto

#include "dota_client_enums.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

static const ::_pb::EnumDescriptor* file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[7];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_dota_5fclient_5fenums_2eproto = nullptr;
const uint32_t TableStruct_dota_5fclient_5fenums_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_dota_5fclient_5fenums_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\027dota_client_enums.proto\032\027dota_shared_e"
  "nums.proto*^\n\023ETournamentTemplate\022\036\n\032k_E"
  "TournamentTemplate_None\020\000\022\'\n#k_ETourname"
  "ntTemplate_AutomatedWin3\020\001*\250\003\n\024ETourname"
  "ntGameState\022\"\n\036k_ETournamentGameState_Un"
  "known\020\000\022#\n\037k_ETournamentGameState_Cancel"
  "ed\020\001\022$\n k_ETournamentGameState_Scheduled"
  "\020\002\022!\n\035k_ETournamentGameState_Active\020\003\022%\n"
  "!k_ETournamentGameState_RadVictory\020\024\022&\n\""
  "k_ETournamentGameState_DireVictory\020\025\022.\n*"
  "k_ETournamentGameState_RadVictoryByForfe"
  "it\020\026\022/\n+k_ETournamentGameState_DireVicto"
  "ryByForfeit\020\027\022(\n$k_ETournamentGameState_"
  "ServerFailure\020(\022$\n k_ETournamentGameStat"
  "e_NotNeeded\020)*\347\006\n\024ETournamentTeamState\022\""
  "\n\036k_ETournamentTeamState_Unknown\020\000\022 \n\034k_"
  "ETournamentTeamState_Node1\020\001\022#\n\036k_ETourn"
  "amentTeamState_NodeMax\020\200\010\022&\n!k_ETourname"
  "ntTeamState_Eliminated\020\263m\022%\n k_ETourname"
  "ntTeamState_Forfeited\020\264m\022\'\n\"k_ETournamen"
  "tTeamState_Finished1st\020\231u\022\'\n\"k_ETourname"
  "ntTeamState_Finished2nd\020\232u\022\'\n\"k_ETournam"
  "entTeamState_Finished3rd\020\233u\022\'\n\"k_ETourna"
  "mentTeamState_Finished4th\020\234u\022\'\n\"k_ETourn"
  "amentTeamState_Finished5th\020\235u\022\'\n\"k_ETour"
  "namentTeamState_Finished6th\020\236u\022\'\n\"k_ETou"
  "rnamentTeamState_Finished7th\020\237u\022\'\n\"k_ETo"
  "urnamentTeamState_Finished8th\020\240u\022\'\n\"k_ET"
  "ournamentTeamState_Finished9th\020\241u\022(\n#k_E"
  "TournamentTeamState_Finished10th\020\242u\022(\n#k"
  "_ETournamentTeamState_Finished11th\020\243u\022(\n"
  "#k_ETournamentTeamState_Finished12th\020\244u\022"
  "(\n#k_ETournamentTeamState_Finished13th\020\245"
  "u\022(\n#k_ETournamentTeamState_Finished14th"
  "\020\246u\022(\n#k_ETournamentTeamState_Finished15"
  "th\020\247u\022(\n#k_ETournamentTeamState_Finished"
  "16th\020\250u*\354\003\n\020ETournamentState\022\036\n\032k_ETourn"
  "amentState_Unknown\020\000\022&\n\"k_ETournamentSta"
  "te_CanceledByAdmin\020\001\022 \n\034k_ETournamentSta"
  "te_Completed\020\002\022\035\n\031k_ETournamentState_Mer"
  "ged\020\003\022$\n k_ETournamentState_ServerFailur"
  "e\020\004\022$\n k_ETournamentState_TeamAbandoned\020"
  "\005\022)\n%k_ETournamentState_TeamTimeoutForfe"
  "it\020\006\022(\n$k_ETournamentState_TeamTimeoutRe"
  "fund\020\007\0222\n.k_ETournamentState_ServerFailu"
  "reGrantedVictory\020\010\0220\n,k_ETournamentState"
  "_TeamTimeoutGrantedVictory\020\t\022!\n\035k_ETourn"
  "amentState_InProgress\020d\022%\n!k_ETournament"
  "State_WaitingToMerge\020e*\314\004\n\024ETournamentNo"
  "deState\022\"\n\036k_ETournamentNodeState_Unknow"
  "n\020\000\022#\n\037k_ETournamentNodeState_Canceled\020\001"
  "\022.\n*k_ETournamentNodeState_TeamsNotYetAs"
  "signed\020\002\022)\n%k_ETournamentNodeState_InBet"
  "weenGames\020\003\022)\n%k_ETournamentNodeState_Ga"
  "meInProgress\020\004\022 \n\034k_ETournamentNodeState"
  "_A_Won\020\005\022 \n\034k_ETournamentNodeState_B_Won"
  "\020\006\022)\n%k_ETournamentNodeState_A_WonByForf"
  "eit\020\007\022)\n%k_ETournamentNodeState_B_WonByF"
  "orfeit\020\010\022 \n\034k_ETournamentNodeState_A_Bye"
  "\020\t\022&\n\"k_ETournamentNodeState_A_Abandoned"
  "\020\n\022(\n$k_ETournamentNodeState_ServerFailu"
  "re\020\013\022+\n\'k_ETournamentNodeState_A_Timeout"
  "Forfeit\020\014\022*\n&k_ETournamentNodeState_A_Ti"
  "meoutRefund\020\r*\307\003\n\025EDOTAGroupMergeResult\022"
  "\036\n\032k_EDOTAGroupMergeResult_OK\020\000\022*\n&k_EDO"
  "TAGroupMergeResult_FAILED_GENERIC\020\001\022&\n\"k"
  "_EDOTAGroupMergeResult_NOT_LEADER\020\002\022,\n(k"
  "_EDOTAGroupMergeResult_TOO_MANY_PLAYERS\020"
  "\003\022,\n(k_EDOTAGroupMergeResult_TOO_MANY_CO"
  "ACHES\020\004\022+\n\'k_EDOTAGroupMergeResult_ENGIN"
  "E_MISMATCH\020\005\022)\n%k_EDOTAGroupMergeResult_"
  "NO_SUCH_GROUP\020\006\0220\n,k_EDOTAGroupMergeResu"
  "lt_OTHER_GROUP_NOT_OPEN\020\007\022+\n\'k_EDOTAGrou"
  "pMergeResult_ALREADY_INVITED\020\010\022\'\n#k_EDOT"
  "AGroupMergeResult_NOT_INVITED\020\t*U\n\020EPart"
  "yBeaconType\022 \n\034k_EPartyBeaconType_Availa"
  "ble\020\000\022\037\n\033k_EPartyBeaconType_Joinable\020\001"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_dota_5fclient_5fenums_2eproto_deps[1] = {
  &::descriptor_table_dota_5fshared_5fenums_2eproto,
};
static ::_pbi::once_flag descriptor_table_dota_5fclient_5fenums_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_dota_5fclient_5fenums_2eproto = {
    false, false, 3078, descriptor_table_protodef_dota_5fclient_5fenums_2eproto,
    "dota_client_enums.proto",
    &descriptor_table_dota_5fclient_5fenums_2eproto_once, descriptor_table_dota_5fclient_5fenums_2eproto_deps, 1, 0,
    schemas, file_default_instances, TableStruct_dota_5fclient_5fenums_2eproto::offsets,
    nullptr, file_level_enum_descriptors_dota_5fclient_5fenums_2eproto,
    file_level_service_descriptors_dota_5fclient_5fenums_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_dota_5fclient_5fenums_2eproto_getter() {
  return &descriptor_table_dota_5fclient_5fenums_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_dota_5fclient_5fenums_2eproto(&descriptor_table_dota_5fclient_5fenums_2eproto);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ETournamentTemplate_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[0];
}
bool ETournamentTemplate_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ETournamentGameState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[1];
}
bool ETournamentGameState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 20:
    case 21:
    case 22:
    case 23:
    case 40:
    case 41:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ETournamentTeamState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[2];
}
bool ETournamentTeamState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 1024:
    case 14003:
    case 14004:
    case 15001:
    case 15002:
    case 15003:
    case 15004:
    case 15005:
    case 15006:
    case 15007:
    case 15008:
    case 15009:
    case 15010:
    case 15011:
    case 15012:
    case 15013:
    case 15014:
    case 15015:
    case 15016:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ETournamentState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[3];
}
bool ETournamentState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 100:
    case 101:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ETournamentNodeState_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[4];
}
bool ETournamentNodeState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EDOTAGroupMergeResult_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[5];
}
bool EDOTAGroupMergeResult_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EPartyBeaconType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_dota_5fclient_5fenums_2eproto);
  return file_level_enum_descriptors_dota_5fclient_5fenums_2eproto[6];
}
bool EPartyBeaconType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>