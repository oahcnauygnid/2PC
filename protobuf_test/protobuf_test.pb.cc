// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protobuf_test.proto

#include "protobuf_test.pb.h"

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

namespace protobuf_test {
PROTOBUF_CONSTEXPR Protobuf_test::Protobuf_test(
    ::_pbi::ConstantInitialized)
  : num_(){}
struct Protobuf_testDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Protobuf_testDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~Protobuf_testDefaultTypeInternal() {}
  union {
    Protobuf_test _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Protobuf_testDefaultTypeInternal _Protobuf_test_default_instance_;
}  // namespace protobuf_test
static ::_pb::Metadata file_level_metadata_protobuf_5ftest_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_protobuf_5ftest_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_protobuf_5ftest_2eproto = nullptr;

const uint32_t TableStruct_protobuf_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protobuf_test::Protobuf_test, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::protobuf_test::Protobuf_test, num_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::protobuf_test::Protobuf_test)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::protobuf_test::_Protobuf_test_default_instance_._instance,
};

const char descriptor_table_protodef_protobuf_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023protobuf_test.proto\022\rprotobuf_test\"\034\n\r"
  "Protobuf_test\022\013\n\003num\030\001 \003(\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_protobuf_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_protobuf_5ftest_2eproto = {
    false, false, 74, descriptor_table_protodef_protobuf_5ftest_2eproto,
    "protobuf_test.proto",
    &descriptor_table_protobuf_5ftest_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_protobuf_5ftest_2eproto::offsets,
    file_level_metadata_protobuf_5ftest_2eproto, file_level_enum_descriptors_protobuf_5ftest_2eproto,
    file_level_service_descriptors_protobuf_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_protobuf_5ftest_2eproto_getter() {
  return &descriptor_table_protobuf_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_protobuf_5ftest_2eproto(&descriptor_table_protobuf_5ftest_2eproto);
namespace protobuf_test {

// ===================================================================

class Protobuf_test::_Internal {
 public:
};

Protobuf_test::Protobuf_test(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  num_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:protobuf_test.Protobuf_test)
}
Protobuf_test::Protobuf_test(const Protobuf_test& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      num_(from.num_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:protobuf_test.Protobuf_test)
}

inline void Protobuf_test::SharedCtor() {
}

Protobuf_test::~Protobuf_test() {
  // @@protoc_insertion_point(destructor:protobuf_test.Protobuf_test)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Protobuf_test::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Protobuf_test::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Protobuf_test::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf_test.Protobuf_test)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  num_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Protobuf_test::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated double num = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_num(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 9) {
          _internal_add_num(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Protobuf_test::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protobuf_test.Protobuf_test)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated double num = 1;
  if (this->_internal_num_size() > 0) {
    target = stream->WriteFixedPacked(1, _internal_num(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protobuf_test.Protobuf_test)
  return target;
}

size_t Protobuf_test::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf_test.Protobuf_test)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double num = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_num_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Protobuf_test::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Protobuf_test::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Protobuf_test::GetClassData() const { return &_class_data_; }

void Protobuf_test::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Protobuf_test *>(to)->MergeFrom(
      static_cast<const Protobuf_test &>(from));
}


void Protobuf_test::MergeFrom(const Protobuf_test& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf_test.Protobuf_test)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  num_.MergeFrom(from.num_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Protobuf_test::CopyFrom(const Protobuf_test& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf_test.Protobuf_test)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Protobuf_test::IsInitialized() const {
  return true;
}

void Protobuf_test::InternalSwap(Protobuf_test* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  num_.InternalSwap(&other->num_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Protobuf_test::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protobuf_5ftest_2eproto_getter, &descriptor_table_protobuf_5ftest_2eproto_once,
      file_level_metadata_protobuf_5ftest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protobuf_test::Protobuf_test*
Arena::CreateMaybeMessage< ::protobuf_test::Protobuf_test >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protobuf_test::Protobuf_test >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
