// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protobuf_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_protobuf_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_protobuf_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_protobuf_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_protobuf_5ftest_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_protobuf_5ftest_2eproto;
namespace protobuf_test {
class Protobuf_test;
struct Protobuf_testDefaultTypeInternal;
extern Protobuf_testDefaultTypeInternal _Protobuf_test_default_instance_;
}  // namespace protobuf_test
PROTOBUF_NAMESPACE_OPEN
template<> ::protobuf_test::Protobuf_test* Arena::CreateMaybeMessage<::protobuf_test::Protobuf_test>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protobuf_test {

// ===================================================================

class Protobuf_test final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protobuf_test.Protobuf_test) */ {
 public:
  inline Protobuf_test() : Protobuf_test(nullptr) {}
  ~Protobuf_test() override;
  explicit PROTOBUF_CONSTEXPR Protobuf_test(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Protobuf_test(const Protobuf_test& from);
  Protobuf_test(Protobuf_test&& from) noexcept
    : Protobuf_test() {
    *this = ::std::move(from);
  }

  inline Protobuf_test& operator=(const Protobuf_test& from) {
    CopyFrom(from);
    return *this;
  }
  inline Protobuf_test& operator=(Protobuf_test&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Protobuf_test& default_instance() {
    return *internal_default_instance();
  }
  static inline const Protobuf_test* internal_default_instance() {
    return reinterpret_cast<const Protobuf_test*>(
               &_Protobuf_test_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Protobuf_test& a, Protobuf_test& b) {
    a.Swap(&b);
  }
  inline void Swap(Protobuf_test* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Protobuf_test* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Protobuf_test* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Protobuf_test>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Protobuf_test& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Protobuf_test& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Protobuf_test* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protobuf_test.Protobuf_test";
  }
  protected:
  explicit Protobuf_test(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumFieldNumber = 1,
  };
  // repeated double num = 1;
  int num_size() const;
  private:
  int _internal_num_size() const;
  public:
  void clear_num();
  private:
  double _internal_num(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_num() const;
  void _internal_add_num(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_num();
  public:
  double num(int index) const;
  void set_num(int index, double value);
  void add_num(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      num() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_num();

  // @@protoc_insertion_point(class_scope:protobuf_test.Protobuf_test)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > num_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_protobuf_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Protobuf_test

// repeated double num = 1;
inline int Protobuf_test::_internal_num_size() const {
  return num_.size();
}
inline int Protobuf_test::num_size() const {
  return _internal_num_size();
}
inline void Protobuf_test::clear_num() {
  num_.Clear();
}
inline double Protobuf_test::_internal_num(int index) const {
  return num_.Get(index);
}
inline double Protobuf_test::num(int index) const {
  // @@protoc_insertion_point(field_get:protobuf_test.Protobuf_test.num)
  return _internal_num(index);
}
inline void Protobuf_test::set_num(int index, double value) {
  num_.Set(index, value);
  // @@protoc_insertion_point(field_set:protobuf_test.Protobuf_test.num)
}
inline void Protobuf_test::_internal_add_num(double value) {
  num_.Add(value);
}
inline void Protobuf_test::add_num(double value) {
  _internal_add_num(value);
  // @@protoc_insertion_point(field_add:protobuf_test.Protobuf_test.num)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
Protobuf_test::_internal_num() const {
  return num_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
Protobuf_test::num() const {
  // @@protoc_insertion_point(field_list:protobuf_test.Protobuf_test.num)
  return _internal_num();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
Protobuf_test::_internal_mutable_num() {
  return &num_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
Protobuf_test::mutable_num() {
  // @@protoc_insertion_point(field_mutable_list:protobuf_test.Protobuf_test.num)
  return _internal_mutable_num();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf_test

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_protobuf_5ftest_2eproto