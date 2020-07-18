//
//  AppDelegate.m
//  screenshot
//
//  Created by mian on 2020/7/16.
//  Copyright © 2020 mian. All rights reserved.
//

#import "AppDelegate.h"
@import CoreGraphics;

@interface AppDelegate ()


@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    CGImageRef img = CGWindowListCreateImage(CGRectMake(10, 50, 100, 100),
                                              kCGWindowListOptionOnScreenOnly,
                                              kCGNullWindowID,
                                              kCGWindowImageDefault);
    
    //拿到原始的像素数据
    CGDataProviderRef provider = CGImageGetDataProvider(img);
    CFDataRef imageData = CGDataProviderCopyData(provider);
    uint8_t *bytes = (uint8_t *)CFDataGetBytePtr(imageData);
    
    NSImage *image = [[NSImage alloc] initWithCGImage:img size:NSZeroSize];
    NSImageView *imgView = [NSImageView imageViewWithImage:image];
    NSLog(@"%f  %f",
          image.size.width,
          imgView.frame.size.width
          );
    imgView.frame = CGRectMake(0, 0, 100, 100);
  
    [self.window.contentView addSubview:imgView];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
