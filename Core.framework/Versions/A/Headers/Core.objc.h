// Objective-C API for talking to v2ray.com/core Go package.
//   gobind -lang=objc v2ray.com/core
//
// File is generated by gobind. Do not edit.

#ifndef __Core_H__
#define __Core_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class CoreAnnotation;
@class CoreConfig;
@class CoreConfigFormat;
@class CoreInboundHandlerConfig;
@class CoreInstance;
@class CoreOutboundHandlerConfig;
@protocol CoreServer;
@class CoreServer;

@protocol CoreServer <NSObject>
- (BOOL)close:(NSError* _Nullable* _Nullable)error;
- (BOOL)start:(NSError* _Nullable* _Nullable)error;
@end

/**
 * Annotation is a concept in V2Ray. This struct is only for documentation. It is not used anywhere.
Annotations begin with "v2ray:" in comment, as metadata of functions or types.
 */
@interface CoreAnnotation : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * API is for types or functions that can be used in other libs. Possible values are:

* v2ray:api:beta for types or functions that are ready for use, but maybe changed in the future.
* v2ray:api:stable for types or functions with guarantee of backward compatibility.
* v2ray:api:deprecated for types or functions that should not be used anymore.

Types or functions without api annotation should not be used externally.
 */
@property (nonatomic) NSString* _Nonnull api;
@end

/**
 * Config is the master config of V2Ray. V2Ray takes this config as input and functions accordingly.
 */
@interface CoreConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field Config.Inbound with unsupported type: []*v2ray.com/core.InboundHandlerConfig

// skipped field Config.Outbound with unsupported type: []*v2ray.com/core.OutboundHandlerConfig

// skipped field Config.App with unsupported type: []*v2ray.com/core/common/serial.TypedMessage

// skipped field Config.Transport with unsupported type: *v2ray.com/core/transport.Config

// skipped field Config.Extension with unsupported type: []*v2ray.com/core/common/serial.TypedMessage

// skipped field Config.XXX_NoUnkeyedLiteral with unsupported type: struct{}

@property (nonatomic) NSData* _Nullable xxX_unrecognized;
@property (nonatomic) int32_t xxX_sizecache;
// skipped method Config.Descriptor with unsupported parameter or return types

// skipped method Config.GetApp with unsupported parameter or return types

// skipped method Config.GetExtension with unsupported parameter or return types

// skipped method Config.GetInbound with unsupported parameter or return types

// skipped method Config.GetOutbound with unsupported parameter or return types

// skipped method Config.GetTransport with unsupported parameter or return types

- (void)protoMessage;
- (void)reset;
- (NSString* _Nonnull)string;
- (void)xxX_DiscardUnknown;
- (NSData* _Nullable)xxX_Marshal:(NSData* _Nullable)b deterministic:(BOOL)deterministic error:(NSError* _Nullable* _Nullable)error;
// skipped method Config.XXX_Merge with unsupported parameter or return types

- (long)xxX_Size;
- (BOOL)xxX_Unmarshal:(NSData* _Nullable)b error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * ConfigFormat is a configurable format of V2Ray config file.
 */
@interface CoreConfigFormat : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
// skipped field ConfigFormat.Extension with unsupported type: []string

// skipped field ConfigFormat.Loader with unsupported type: v2ray.com/core.ConfigLoader

@end

/**
 * InboundHandlerConfig is the configuration for inbound handler.
 */
@interface CoreInboundHandlerConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Tag of the inbound handler. The tag must be unique among all inbound handlers
 */
@property (nonatomic) NSString* _Nonnull tag;
// skipped field InboundHandlerConfig.ReceiverSettings with unsupported type: *v2ray.com/core/common/serial.TypedMessage

// skipped field InboundHandlerConfig.ProxySettings with unsupported type: *v2ray.com/core/common/serial.TypedMessage

// skipped field InboundHandlerConfig.XXX_NoUnkeyedLiteral with unsupported type: struct{}

@property (nonatomic) NSData* _Nullable xxX_unrecognized;
@property (nonatomic) int32_t xxX_sizecache;
// skipped method InboundHandlerConfig.Descriptor with unsupported parameter or return types

// skipped method InboundHandlerConfig.GetProxySettings with unsupported parameter or return types

// skipped method InboundHandlerConfig.GetReceiverSettings with unsupported parameter or return types

- (NSString* _Nonnull)getTag;
- (void)protoMessage;
- (void)reset;
- (NSString* _Nonnull)string;
- (void)xxX_DiscardUnknown;
- (NSData* _Nullable)xxX_Marshal:(NSData* _Nullable)b deterministic:(BOOL)deterministic error:(NSError* _Nullable* _Nullable)error;
// skipped method InboundHandlerConfig.XXX_Merge with unsupported parameter or return types

- (long)xxX_Size;
- (BOOL)xxX_Unmarshal:(NSData* _Nullable)b error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * Instance combines all functionalities in V2Ray.
 */
@interface CoreInstance : NSObject <goSeqRefInterface, CoreServer> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped method Instance.AddFeature with unsupported parameter or return types

/**
 * Close shutdown the V2Ray instance.
 */
- (BOOL)close:(NSError* _Nullable* _Nullable)error;
// skipped method Instance.GetFeature with unsupported parameter or return types

// skipped method Instance.RequireFeatures with unsupported parameter or return types

/**
 * Start starts the V2Ray instance, including all registered features. When Start returns error, the state of the instance is unknown.
A V2Ray instance can be started only once. Upon closing, the instance is not guaranteed to start again.

v2ray:api:stable
 */
- (BOOL)start:(NSError* _Nullable* _Nullable)error;
// skipped method Instance.Type with unsupported parameter or return types

@end

/**
 * OutboundHandlerConfig is the configuration for outbound handler.
 */
@interface CoreOutboundHandlerConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Tag of this outbound handler.
 */
@property (nonatomic) NSString* _Nonnull tag;
// skipped field OutboundHandlerConfig.SenderSettings with unsupported type: *v2ray.com/core/common/serial.TypedMessage

// skipped field OutboundHandlerConfig.ProxySettings with unsupported type: *v2ray.com/core/common/serial.TypedMessage

/**
 * If not zero, this outbound will be expired in seconds. Not used for now.
 */
@property (nonatomic) int64_t expire;
/**
 * Comment of this outbound handler. Not used for now.
 */
@property (nonatomic) NSString* _Nonnull comment;
// skipped field OutboundHandlerConfig.XXX_NoUnkeyedLiteral with unsupported type: struct{}

@property (nonatomic) NSData* _Nullable xxX_unrecognized;
@property (nonatomic) int32_t xxX_sizecache;
// skipped method OutboundHandlerConfig.Descriptor with unsupported parameter or return types

- (NSString* _Nonnull)getComment;
- (int64_t)getExpire;
// skipped method OutboundHandlerConfig.GetProxySettings with unsupported parameter or return types

// skipped method OutboundHandlerConfig.GetSenderSettings with unsupported parameter or return types

- (NSString* _Nonnull)getTag;
- (void)protoMessage;
- (void)reset;
- (NSString* _Nonnull)string;
- (void)xxX_DiscardUnknown;
- (NSData* _Nullable)xxX_Marshal:(NSData* _Nullable)b deterministic:(BOOL)deterministic error:(NSError* _Nullable* _Nullable)error;
// skipped method OutboundHandlerConfig.XXX_Merge with unsupported parameter or return types

- (long)xxX_Size;
- (BOOL)xxX_Unmarshal:(NSData* _Nullable)b error:(NSError* _Nullable* _Nullable)error;
@end

FOUNDATION_EXPORT BOOL CoreAddInboundHandler(CoreInstance* _Nullable server, CoreInboundHandlerConfig* _Nullable config, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BOOL CoreAddOutboundHandler(CoreInstance* _Nullable server, CoreOutboundHandlerConfig* _Nullable config, NSError* _Nullable* _Nullable error);

// skipped function CreateObject with unsupported parameter or return types


// skipped function Dial with unsupported parameter or return types


// skipped function DialUDP with unsupported parameter or return types


// skipped function FromContext with unsupported parameter or return types


// skipped function LoadConfig with unsupported parameter or return types


// skipped function MustFromContext with unsupported parameter or return types


/**
 * New returns a new V2Ray instance based on given configuration.
The instance is not started at this point.
To ensure V2Ray instance works properly, the config must contain one Dispatcher, one InboundHandlerManager and one OutboundHandlerManager. Other features are optional.
 */
FOUNDATION_EXPORT CoreInstance* _Nullable CoreNew(CoreConfig* _Nullable config, NSError* _Nullable* _Nullable error);

/**
 * RegisterConfigLoader add a new ConfigLoader.
 */
FOUNDATION_EXPORT BOOL CoreRegisterConfigLoader(CoreConfigFormat* _Nullable format, NSError* _Nullable* _Nullable error);

// skipped function RequireFeatures with unsupported parameter or return types


// skipped function ServerType with unsupported parameter or return types


/**
 * StartInstance starts a new V2Ray instance with given serialized config.
By default V2Ray only support config in protobuf format, i.e., configFormat = "protobuf". Caller need to load other packages to add JSON support.

v2ray:api:stable
 */
FOUNDATION_EXPORT CoreInstance* _Nullable CoreStartInstance(NSString* _Nullable configFormat, NSData* _Nullable configBytes, NSError* _Nullable* _Nullable error);

/**
 * Version returns V2Ray's version as a string, in the form of "x.y.z" where x, y and z are numbers.
".z" part may be omitted in regular releases.
 */
FOUNDATION_EXPORT NSString* _Nonnull CoreVersion(void);

// skipped function VersionStatement with unsupported parameter or return types


@class CoreServer;

/**
 * Server is an instance of V2Ray. At any time, there must be at most one Server instance running.
 */
@interface CoreServer : NSObject <goSeqRefInterface, CoreServer> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BOOL)close:(NSError* _Nullable* _Nullable)error;
- (BOOL)start:(NSError* _Nullable* _Nullable)error;
@end

#endif