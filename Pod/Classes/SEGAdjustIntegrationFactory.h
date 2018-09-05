#import <Foundation/Foundation.h>
#import <Analytics/SEGIntegrationFactory.h>
#import "SEGAdjustIntegration.h"


@interface SEGAdjustIntegrationFactory : NSObject <SEGIntegrationFactory>

+ (instancetype)instanceWithDelegate:(id <SEGAdjustIntegrationDelegate>)delegate;

@end
