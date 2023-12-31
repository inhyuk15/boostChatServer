// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_chat_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_chat_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_chat_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_chat_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_chat_2eproto;
namespace chat {
class ChatMessage;
struct ChatMessageDefaultTypeInternal;
extern ChatMessageDefaultTypeInternal _ChatMessage_default_instance_;
}  // namespace chat
PROTOBUF_NAMESPACE_OPEN
template<> ::chat::ChatMessage* Arena::CreateMaybeMessage<::chat::ChatMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chat {

enum DataType : int {
  TEXT = 0,
  IMAGE = 1,
  SYSTEM = 2,
  DataType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  DataType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool DataType_IsValid(int value);
constexpr DataType DataType_MIN = TEXT;
constexpr DataType DataType_MAX = SYSTEM;
constexpr int DataType_ARRAYSIZE = DataType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DataType_descriptor();
template<typename T>
inline const std::string& DataType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, DataType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function DataType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    DataType_descriptor(), enum_t_value);
}
inline bool DataType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, DataType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<DataType>(
    DataType_descriptor(), name, value);
}
enum SystemCode : int {
  NONE = 0,
  TIMEOUT = 1,
  SystemCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  SystemCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool SystemCode_IsValid(int value);
constexpr SystemCode SystemCode_MIN = NONE;
constexpr SystemCode SystemCode_MAX = TIMEOUT;
constexpr int SystemCode_ARRAYSIZE = SystemCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SystemCode_descriptor();
template<typename T>
inline const std::string& SystemCode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SystemCode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SystemCode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    SystemCode_descriptor(), enum_t_value);
}
inline bool SystemCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, SystemCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<SystemCode>(
    SystemCode_descriptor(), name, value);
}
// ===================================================================

class ChatMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chat.ChatMessage) */ {
 public:
  inline ChatMessage() : ChatMessage(nullptr) {}
  ~ChatMessage() override;
  explicit PROTOBUF_CONSTEXPR ChatMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ChatMessage(const ChatMessage& from);
  ChatMessage(ChatMessage&& from) noexcept
    : ChatMessage() {
    *this = ::std::move(from);
  }

  inline ChatMessage& operator=(const ChatMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline ChatMessage& operator=(ChatMessage&& from) noexcept {
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
  static const ChatMessage& default_instance() {
    return *internal_default_instance();
  }
  enum ContentCase {
    kMessageText = 4,
    kImageData = 5,
    CONTENT_NOT_SET = 0,
  };

  static inline const ChatMessage* internal_default_instance() {
    return reinterpret_cast<const ChatMessage*>(
               &_ChatMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ChatMessage& a, ChatMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(ChatMessage* other) {
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
  void UnsafeArenaSwap(ChatMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ChatMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ChatMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ChatMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ChatMessage& from) {
    ChatMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ChatMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chat.ChatMessage";
  }
  protected:
  explicit ChatMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserNameFieldNumber = 1,
    kFileExtensionFieldNumber = 7,
    kTimestampFieldNumber = 2,
    kDataTypeFieldNumber = 3,
    kSystemCodeFieldNumber = 6,
    kMessageTextFieldNumber = 4,
    kImageDataFieldNumber = 5,
  };
  // string user_name = 1;
  void clear_user_name();
  const std::string& user_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_user_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_user_name();
  PROTOBUF_NODISCARD std::string* release_user_name();
  void set_allocated_user_name(std::string* user_name);
  private:
  const std::string& _internal_user_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_user_name(const std::string& value);
  std::string* _internal_mutable_user_name();
  public:

  // string file_extension = 7;
  void clear_file_extension();
  const std::string& file_extension() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_file_extension(ArgT0&& arg0, ArgT... args);
  std::string* mutable_file_extension();
  PROTOBUF_NODISCARD std::string* release_file_extension();
  void set_allocated_file_extension(std::string* file_extension);
  private:
  const std::string& _internal_file_extension() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_file_extension(const std::string& value);
  std::string* _internal_mutable_file_extension();
  public:

  // uint64 timestamp = 2;
  void clear_timestamp();
  uint64_t timestamp() const;
  void set_timestamp(uint64_t value);
  private:
  uint64_t _internal_timestamp() const;
  void _internal_set_timestamp(uint64_t value);
  public:

  // .chat.DataType data_type = 3;
  void clear_data_type();
  ::chat::DataType data_type() const;
  void set_data_type(::chat::DataType value);
  private:
  ::chat::DataType _internal_data_type() const;
  void _internal_set_data_type(::chat::DataType value);
  public:

  // .chat.SystemCode system_code = 6;
  void clear_system_code();
  ::chat::SystemCode system_code() const;
  void set_system_code(::chat::SystemCode value);
  private:
  ::chat::SystemCode _internal_system_code() const;
  void _internal_set_system_code(::chat::SystemCode value);
  public:

  // string message_text = 4;
  bool has_message_text() const;
  private:
  bool _internal_has_message_text() const;
  public:
  void clear_message_text();
  const std::string& message_text() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message_text(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message_text();
  PROTOBUF_NODISCARD std::string* release_message_text();
  void set_allocated_message_text(std::string* message_text);
  private:
  const std::string& _internal_message_text() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message_text(const std::string& value);
  std::string* _internal_mutable_message_text();
  public:

  // bytes image_data = 5;
  bool has_image_data() const;
  private:
  bool _internal_has_image_data() const;
  public:
  void clear_image_data();
  const std::string& image_data() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_image_data(ArgT0&& arg0, ArgT... args);
  std::string* mutable_image_data();
  PROTOBUF_NODISCARD std::string* release_image_data();
  void set_allocated_image_data(std::string* image_data);
  private:
  const std::string& _internal_image_data() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_image_data(const std::string& value);
  std::string* _internal_mutable_image_data();
  public:

  void clear_content();
  ContentCase content_case() const;
  // @@protoc_insertion_point(class_scope:chat.ChatMessage)
 private:
  class _Internal;
  void set_has_message_text();
  void set_has_image_data();

  inline bool has_content() const;
  inline void clear_has_content();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr user_name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr file_extension_;
    uint64_t timestamp_;
    int data_type_;
    int system_code_;
    union ContentUnion {
      constexpr ContentUnion() : _constinit_{} {}
        ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_text_;
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr image_data_;
    } content_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    uint32_t _oneof_case_[1];

  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_chat_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChatMessage

// string user_name = 1;
inline void ChatMessage::clear_user_name() {
  _impl_.user_name_.ClearToEmpty();
}
inline const std::string& ChatMessage::user_name() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.user_name)
  return _internal_user_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ChatMessage::set_user_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.user_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:chat.ChatMessage.user_name)
}
inline std::string* ChatMessage::mutable_user_name() {
  std::string* _s = _internal_mutable_user_name();
  // @@protoc_insertion_point(field_mutable:chat.ChatMessage.user_name)
  return _s;
}
inline const std::string& ChatMessage::_internal_user_name() const {
  return _impl_.user_name_.Get();
}
inline void ChatMessage::_internal_set_user_name(const std::string& value) {
  
  _impl_.user_name_.Set(value, GetArenaForAllocation());
}
inline std::string* ChatMessage::_internal_mutable_user_name() {
  
  return _impl_.user_name_.Mutable(GetArenaForAllocation());
}
inline std::string* ChatMessage::release_user_name() {
  // @@protoc_insertion_point(field_release:chat.ChatMessage.user_name)
  return _impl_.user_name_.Release();
}
inline void ChatMessage::set_allocated_user_name(std::string* user_name) {
  if (user_name != nullptr) {
    
  } else {
    
  }
  _impl_.user_name_.SetAllocated(user_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.user_name_.IsDefault()) {
    _impl_.user_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:chat.ChatMessage.user_name)
}

// uint64 timestamp = 2;
inline void ChatMessage::clear_timestamp() {
  _impl_.timestamp_ = uint64_t{0u};
}
inline uint64_t ChatMessage::_internal_timestamp() const {
  return _impl_.timestamp_;
}
inline uint64_t ChatMessage::timestamp() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.timestamp)
  return _internal_timestamp();
}
inline void ChatMessage::_internal_set_timestamp(uint64_t value) {
  
  _impl_.timestamp_ = value;
}
inline void ChatMessage::set_timestamp(uint64_t value) {
  _internal_set_timestamp(value);
  // @@protoc_insertion_point(field_set:chat.ChatMessage.timestamp)
}

// .chat.DataType data_type = 3;
inline void ChatMessage::clear_data_type() {
  _impl_.data_type_ = 0;
}
inline ::chat::DataType ChatMessage::_internal_data_type() const {
  return static_cast< ::chat::DataType >(_impl_.data_type_);
}
inline ::chat::DataType ChatMessage::data_type() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.data_type)
  return _internal_data_type();
}
inline void ChatMessage::_internal_set_data_type(::chat::DataType value) {
  
  _impl_.data_type_ = value;
}
inline void ChatMessage::set_data_type(::chat::DataType value) {
  _internal_set_data_type(value);
  // @@protoc_insertion_point(field_set:chat.ChatMessage.data_type)
}

// string message_text = 4;
inline bool ChatMessage::_internal_has_message_text() const {
  return content_case() == kMessageText;
}
inline bool ChatMessage::has_message_text() const {
  return _internal_has_message_text();
}
inline void ChatMessage::set_has_message_text() {
  _impl_._oneof_case_[0] = kMessageText;
}
inline void ChatMessage::clear_message_text() {
  if (_internal_has_message_text()) {
    _impl_.content_.message_text_.Destroy();
    clear_has_content();
  }
}
inline const std::string& ChatMessage::message_text() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.message_text)
  return _internal_message_text();
}
template <typename ArgT0, typename... ArgT>
inline void ChatMessage::set_message_text(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_message_text()) {
    clear_content();
    set_has_message_text();
    _impl_.content_.message_text_.InitDefault();
  }
  _impl_.content_.message_text_.Set( static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:chat.ChatMessage.message_text)
}
inline std::string* ChatMessage::mutable_message_text() {
  std::string* _s = _internal_mutable_message_text();
  // @@protoc_insertion_point(field_mutable:chat.ChatMessage.message_text)
  return _s;
}
inline const std::string& ChatMessage::_internal_message_text() const {
  if (_internal_has_message_text()) {
    return _impl_.content_.message_text_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void ChatMessage::_internal_set_message_text(const std::string& value) {
  if (!_internal_has_message_text()) {
    clear_content();
    set_has_message_text();
    _impl_.content_.message_text_.InitDefault();
  }
  _impl_.content_.message_text_.Set(value, GetArenaForAllocation());
}
inline std::string* ChatMessage::_internal_mutable_message_text() {
  if (!_internal_has_message_text()) {
    clear_content();
    set_has_message_text();
    _impl_.content_.message_text_.InitDefault();
  }
  return _impl_.content_.message_text_.Mutable(      GetArenaForAllocation());
}
inline std::string* ChatMessage::release_message_text() {
  // @@protoc_insertion_point(field_release:chat.ChatMessage.message_text)
  if (_internal_has_message_text()) {
    clear_has_content();
    return _impl_.content_.message_text_.Release();
  } else {
    return nullptr;
  }
}
inline void ChatMessage::set_allocated_message_text(std::string* message_text) {
  if (has_content()) {
    clear_content();
  }
  if (message_text != nullptr) {
    set_has_message_text();
    _impl_.content_.message_text_.InitAllocated(message_text, GetArenaForAllocation());
  }
  // @@protoc_insertion_point(field_set_allocated:chat.ChatMessage.message_text)
}

// bytes image_data = 5;
inline bool ChatMessage::_internal_has_image_data() const {
  return content_case() == kImageData;
}
inline bool ChatMessage::has_image_data() const {
  return _internal_has_image_data();
}
inline void ChatMessage::set_has_image_data() {
  _impl_._oneof_case_[0] = kImageData;
}
inline void ChatMessage::clear_image_data() {
  if (_internal_has_image_data()) {
    _impl_.content_.image_data_.Destroy();
    clear_has_content();
  }
}
inline const std::string& ChatMessage::image_data() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.image_data)
  return _internal_image_data();
}
template <typename ArgT0, typename... ArgT>
inline void ChatMessage::set_image_data(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_image_data()) {
    clear_content();
    set_has_image_data();
    _impl_.content_.image_data_.InitDefault();
  }
  _impl_.content_.image_data_.SetBytes( static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:chat.ChatMessage.image_data)
}
inline std::string* ChatMessage::mutable_image_data() {
  std::string* _s = _internal_mutable_image_data();
  // @@protoc_insertion_point(field_mutable:chat.ChatMessage.image_data)
  return _s;
}
inline const std::string& ChatMessage::_internal_image_data() const {
  if (_internal_has_image_data()) {
    return _impl_.content_.image_data_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void ChatMessage::_internal_set_image_data(const std::string& value) {
  if (!_internal_has_image_data()) {
    clear_content();
    set_has_image_data();
    _impl_.content_.image_data_.InitDefault();
  }
  _impl_.content_.image_data_.Set(value, GetArenaForAllocation());
}
inline std::string* ChatMessage::_internal_mutable_image_data() {
  if (!_internal_has_image_data()) {
    clear_content();
    set_has_image_data();
    _impl_.content_.image_data_.InitDefault();
  }
  return _impl_.content_.image_data_.Mutable(      GetArenaForAllocation());
}
inline std::string* ChatMessage::release_image_data() {
  // @@protoc_insertion_point(field_release:chat.ChatMessage.image_data)
  if (_internal_has_image_data()) {
    clear_has_content();
    return _impl_.content_.image_data_.Release();
  } else {
    return nullptr;
  }
}
inline void ChatMessage::set_allocated_image_data(std::string* image_data) {
  if (has_content()) {
    clear_content();
  }
  if (image_data != nullptr) {
    set_has_image_data();
    _impl_.content_.image_data_.InitAllocated(image_data, GetArenaForAllocation());
  }
  // @@protoc_insertion_point(field_set_allocated:chat.ChatMessage.image_data)
}

// .chat.SystemCode system_code = 6;
inline void ChatMessage::clear_system_code() {
  _impl_.system_code_ = 0;
}
inline ::chat::SystemCode ChatMessage::_internal_system_code() const {
  return static_cast< ::chat::SystemCode >(_impl_.system_code_);
}
inline ::chat::SystemCode ChatMessage::system_code() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.system_code)
  return _internal_system_code();
}
inline void ChatMessage::_internal_set_system_code(::chat::SystemCode value) {
  
  _impl_.system_code_ = value;
}
inline void ChatMessage::set_system_code(::chat::SystemCode value) {
  _internal_set_system_code(value);
  // @@protoc_insertion_point(field_set:chat.ChatMessage.system_code)
}

// string file_extension = 7;
inline void ChatMessage::clear_file_extension() {
  _impl_.file_extension_.ClearToEmpty();
}
inline const std::string& ChatMessage::file_extension() const {
  // @@protoc_insertion_point(field_get:chat.ChatMessage.file_extension)
  return _internal_file_extension();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ChatMessage::set_file_extension(ArgT0&& arg0, ArgT... args) {
 
 _impl_.file_extension_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:chat.ChatMessage.file_extension)
}
inline std::string* ChatMessage::mutable_file_extension() {
  std::string* _s = _internal_mutable_file_extension();
  // @@protoc_insertion_point(field_mutable:chat.ChatMessage.file_extension)
  return _s;
}
inline const std::string& ChatMessage::_internal_file_extension() const {
  return _impl_.file_extension_.Get();
}
inline void ChatMessage::_internal_set_file_extension(const std::string& value) {
  
  _impl_.file_extension_.Set(value, GetArenaForAllocation());
}
inline std::string* ChatMessage::_internal_mutable_file_extension() {
  
  return _impl_.file_extension_.Mutable(GetArenaForAllocation());
}
inline std::string* ChatMessage::release_file_extension() {
  // @@protoc_insertion_point(field_release:chat.ChatMessage.file_extension)
  return _impl_.file_extension_.Release();
}
inline void ChatMessage::set_allocated_file_extension(std::string* file_extension) {
  if (file_extension != nullptr) {
    
  } else {
    
  }
  _impl_.file_extension_.SetAllocated(file_extension, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.file_extension_.IsDefault()) {
    _impl_.file_extension_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:chat.ChatMessage.file_extension)
}

inline bool ChatMessage::has_content() const {
  return content_case() != CONTENT_NOT_SET;
}
inline void ChatMessage::clear_has_content() {
  _impl_._oneof_case_[0] = CONTENT_NOT_SET;
}
inline ChatMessage::ContentCase ChatMessage::content_case() const {
  return ChatMessage::ContentCase(_impl_._oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace chat

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::chat::DataType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::chat::DataType>() {
  return ::chat::DataType_descriptor();
}
template <> struct is_proto_enum< ::chat::SystemCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::chat::SystemCode>() {
  return ::chat::SystemCode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_chat_2eproto
