// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: heartbeat.proto

#include "heartbeat.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace heartbeat {
class HeartBeatMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<HeartBeatMessage>
      _instance;
} _HeartBeatMessage_default_instance_;
}  // namespace heartbeat
namespace protobuf_heartbeat_2eproto {
static void InitDefaultsHeartBeatMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::heartbeat::_HeartBeatMessage_default_instance_;
    new (ptr) ::heartbeat::HeartBeatMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::heartbeat::HeartBeatMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_HeartBeatMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsHeartBeatMessage}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_HeartBeatMessage.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, datetime_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, hostname_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, ip_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, info_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, info2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::heartbeat::HeartBeatMessage, info3_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::heartbeat::HeartBeatMessage)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::heartbeat::_HeartBeatMessage_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "heartbeat.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\017heartbeat.proto\022\theartbeat\"n\n\020HeartBea"
      "tMessage\022\020\n\010dateTime\030\001 \001(\003\022\020\n\010hostName\030\002"
      " \001(\t\022\n\n\002ip\030\003 \001(\t\022\014\n\004info\030\004 \001(\t\022\r\n\005info2\030"
      "\005 \001(\t\022\r\n\005info3\030\006 \001(\003b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 148);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "heartbeat.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_heartbeat_2eproto
namespace heartbeat {

// ===================================================================

void HeartBeatMessage::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int HeartBeatMessage::kDateTimeFieldNumber;
const int HeartBeatMessage::kHostNameFieldNumber;
const int HeartBeatMessage::kIpFieldNumber;
const int HeartBeatMessage::kInfoFieldNumber;
const int HeartBeatMessage::kInfo2FieldNumber;
const int HeartBeatMessage::kInfo3FieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

HeartBeatMessage::HeartBeatMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_heartbeat_2eproto::scc_info_HeartBeatMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:heartbeat.HeartBeatMessage)
}
HeartBeatMessage::HeartBeatMessage(const HeartBeatMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  hostname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.hostname().size() > 0) {
    hostname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.hostname_);
  }
  ip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.ip().size() > 0) {
    ip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_);
  }
  info_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.info().size() > 0) {
    info_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.info_);
  }
  info2_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.info2().size() > 0) {
    info2_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.info2_);
  }
  ::memcpy(&datetime_, &from.datetime_,
    static_cast<size_t>(reinterpret_cast<char*>(&info3_) -
    reinterpret_cast<char*>(&datetime_)) + sizeof(info3_));
  // @@protoc_insertion_point(copy_constructor:heartbeat.HeartBeatMessage)
}

void HeartBeatMessage::SharedCtor() {
  hostname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info2_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&datetime_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&info3_) -
      reinterpret_cast<char*>(&datetime_)) + sizeof(info3_));
}

HeartBeatMessage::~HeartBeatMessage() {
  // @@protoc_insertion_point(destructor:heartbeat.HeartBeatMessage)
  SharedDtor();
}

void HeartBeatMessage::SharedDtor() {
  hostname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ip_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info2_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void HeartBeatMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* HeartBeatMessage::descriptor() {
  ::protobuf_heartbeat_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_heartbeat_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const HeartBeatMessage& HeartBeatMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_heartbeat_2eproto::scc_info_HeartBeatMessage.base);
  return *internal_default_instance();
}


void HeartBeatMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:heartbeat.HeartBeatMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  hostname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info2_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&datetime_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&info3_) -
      reinterpret_cast<char*>(&datetime_)) + sizeof(info3_));
  _internal_metadata_.Clear();
}

bool HeartBeatMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:heartbeat.HeartBeatMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int64 dateTime = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &datetime_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string hostName = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_hostname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->hostname().data(), static_cast<int>(this->hostname().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "heartbeat.HeartBeatMessage.hostName"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string ip = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ip()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->ip().data(), static_cast<int>(this->ip().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "heartbeat.HeartBeatMessage.ip"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string info = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_info()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->info().data(), static_cast<int>(this->info().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "heartbeat.HeartBeatMessage.info"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string info2 = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_info2()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->info2().data(), static_cast<int>(this->info2().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "heartbeat.HeartBeatMessage.info2"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 info3 = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &info3_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:heartbeat.HeartBeatMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:heartbeat.HeartBeatMessage)
  return false;
#undef DO_
}

void HeartBeatMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:heartbeat.HeartBeatMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 dateTime = 1;
  if (this->datetime() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->datetime(), output);
  }

  // string hostName = 2;
  if (this->hostname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->hostname().data(), static_cast<int>(this->hostname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.hostName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->hostname(), output);
  }

  // string ip = 3;
  if (this->ip().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ip().data(), static_cast<int>(this->ip().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.ip");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->ip(), output);
  }

  // string info = 4;
  if (this->info().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->info().data(), static_cast<int>(this->info().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.info");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->info(), output);
  }

  // string info2 = 5;
  if (this->info2().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->info2().data(), static_cast<int>(this->info2().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.info2");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->info2(), output);
  }

  // int64 info3 = 6;
  if (this->info3() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(6, this->info3(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:heartbeat.HeartBeatMessage)
}

::google::protobuf::uint8* HeartBeatMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:heartbeat.HeartBeatMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 dateTime = 1;
  if (this->datetime() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->datetime(), target);
  }

  // string hostName = 2;
  if (this->hostname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->hostname().data(), static_cast<int>(this->hostname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.hostName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->hostname(), target);
  }

  // string ip = 3;
  if (this->ip().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ip().data(), static_cast<int>(this->ip().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.ip");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->ip(), target);
  }

  // string info = 4;
  if (this->info().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->info().data(), static_cast<int>(this->info().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.info");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->info(), target);
  }

  // string info2 = 5;
  if (this->info2().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->info2().data(), static_cast<int>(this->info2().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "heartbeat.HeartBeatMessage.info2");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->info2(), target);
  }

  // int64 info3 = 6;
  if (this->info3() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(6, this->info3(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:heartbeat.HeartBeatMessage)
  return target;
}

size_t HeartBeatMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:heartbeat.HeartBeatMessage)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string hostName = 2;
  if (this->hostname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->hostname());
  }

  // string ip = 3;
  if (this->ip().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->ip());
  }

  // string info = 4;
  if (this->info().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->info());
  }

  // string info2 = 5;
  if (this->info2().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->info2());
  }

  // int64 dateTime = 1;
  if (this->datetime() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->datetime());
  }

  // int64 info3 = 6;
  if (this->info3() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->info3());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void HeartBeatMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:heartbeat.HeartBeatMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const HeartBeatMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const HeartBeatMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:heartbeat.HeartBeatMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:heartbeat.HeartBeatMessage)
    MergeFrom(*source);
  }
}

void HeartBeatMessage::MergeFrom(const HeartBeatMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:heartbeat.HeartBeatMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.hostname().size() > 0) {

    hostname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.hostname_);
  }
  if (from.ip().size() > 0) {

    ip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ip_);
  }
  if (from.info().size() > 0) {

    info_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.info_);
  }
  if (from.info2().size() > 0) {

    info2_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.info2_);
  }
  if (from.datetime() != 0) {
    set_datetime(from.datetime());
  }
  if (from.info3() != 0) {
    set_info3(from.info3());
  }
}

void HeartBeatMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:heartbeat.HeartBeatMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeartBeatMessage::CopyFrom(const HeartBeatMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:heartbeat.HeartBeatMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeartBeatMessage::IsInitialized() const {
  return true;
}

void HeartBeatMessage::Swap(HeartBeatMessage* other) {
  if (other == this) return;
  InternalSwap(other);
}
void HeartBeatMessage::InternalSwap(HeartBeatMessage* other) {
  using std::swap;
  hostname_.Swap(&other->hostname_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  ip_.Swap(&other->ip_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  info_.Swap(&other->info_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  info2_.Swap(&other->info2_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(datetime_, other->datetime_);
  swap(info3_, other->info3_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata HeartBeatMessage::GetMetadata() const {
  protobuf_heartbeat_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_heartbeat_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace heartbeat
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::heartbeat::HeartBeatMessage* Arena::CreateMaybeMessage< ::heartbeat::HeartBeatMessage >(Arena* arena) {
  return Arena::CreateInternal< ::heartbeat::HeartBeatMessage >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
