#import "SEGAdjustIntegrationFactory.h"


@interface SEGAdjustIntegrationFactory ()

@property (nonatomic, weak) id <SEGAdjustIntegrationDelegate> delegate;

@end


@implementation SEGAdjustIntegrationFactory

+ (instancetype)instanceWithDelegate:(id <SEGAdjustIntegrationDelegate>)delegate
{
    static dispatch_once_t once;
    static SEGAdjustIntegrationFactory *sharedInstance;
    dispatch_once(&once, ^{
        sharedInstance = [[self alloc] initWithDelegate:delegate];
    });
    return sharedInstance;
}

- (instancetype)initWithDelegate:(id <SEGAdjustIntegrationDelegate>)delegate
{
    self = [super init];
    self.delegate = delegate;
    return self;
}

- (id<SEGIntegration>)createWithSettings:(NSDictionary *)settings forAnalytics:(SEGAnalytics *)analytics
{
    return [[SEGAdjustIntegration alloc] initWithSettings:settings analytics:analytics delegate:self.delegate];
}

- (NSString *)key
{
    return @"Adjust";
}

@end
