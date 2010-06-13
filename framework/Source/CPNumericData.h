#import <Foundation/Foundation.h>
#import "CPNumericDataType.h"

@interface CPNumericData : NSObject <NSCopying, NSMutableCopying, NSCoding> {
@private
    NSData *data;
    CPNumericDataType dataType;
    NSArray *shape; // array of dimension shapes (NSNumber<unsigned>)
}

/// @name Data Buffer
/// @{
@property (copy, readonly) NSData *data;
@property (readonly) const void *bytes;
@property (readonly) NSUInteger length;
///	@}

/// @name Data Format
/// @{
@property (assign, readonly) CPNumericDataType dataType;
@property (readonly) CPDataTypeFormat dataTypeFormat;
@property (readonly) NSUInteger sampleBytes;
@property (readonly) CFByteOrder byteOrder;
///	@}

/// @name Dimensions
/// @{
@property (copy, readonly) NSArray *shape;
@property (readonly) NSUInteger numberOfDimensions;
@property (readonly) NSUInteger numberOfSamples;
///	@}

/// @name Factory Methods
/// @{
+(CPNumericData *)numericDataWithData:(NSData *)newData
							 dataType:(CPNumericDataType)newDataType
                                shape:(NSArray *)shapeArray;
///	@}

/// @name Initialization
/// @{
-(id)initWithData:(NSData *)newData
		 dataType:(CPNumericDataType)newDataType
            shape:(NSArray *)shapeArray;

-(id)initWithData:(NSData *)newData
   dataTypeString:(NSString *)newDataTypeString
            shape:(NSArray *)shapeArray;
///	@}

/// @name Samples
/// @{
-(void *)samplePointer:(NSUInteger)sample;
-(NSNumber *)sampleValue:(NSUInteger)sample;
///	@}

@end