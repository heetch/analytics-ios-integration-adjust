#import <Foundation/Foundation.h>
#import <Analytics/SEGAnalytics.h>
#import <Adjust/Adjust.h>
#import "SEGAdjustAppSecret.h"


@class SEGAdjustIntegration;

@protocol SEGAdjustIntegrationDelegate <NSObject>

@optional
-(SEGAdjustAppSecret * _Nonnull)appSecretForAdjustIntegration:(SEGAdjustIntegration * _Nonnull)adjustIntegration;
-(void)adjustIntegration:(SEGAdjustIntegration * _Nonnull)adjustIntegration attributionChanged:(ADJAttribution * _Nonnull)attribution;

@end

@interface SEGAdjustIntegration : NSObject <SEGIntegration, AdjustDelegate>

@property (nonatomic, strong) NSDictionary                      *settings;
@property (nonatomic, strong) SEGAnalytics                      *analytics;
@property (nonatomic, weak)   id <SEGAdjustIntegrationDelegate>  delegate;

- (instancetype)initWithSettings:(NSDictionary *)settings analytics:(SEGAnalytics *)analytics delegate:(id <SEGAdjustIntegrationDelegate>)delegate;

@end
