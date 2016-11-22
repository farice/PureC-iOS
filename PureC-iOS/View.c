//
//  ViewController.c
//  PureC-iOS
//
//  Created by Faris Sbahi on 11/22/16.
//
#include <objc/runtime.h>
#include <CoreGraphics/CoreGraphics.h>

Class ViewClass;

extern CGContextRef UIGraphicsGetCurrentContext();

void View_drawRect(id self, SEL _cmd, CGRect rect)
{
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextSetFillColor(context, (CGFloat []){ 1, 1, 1, 1 });
    
    // draw screen
    CGContextAddRect(context, (struct CGRect) { 0, 0, 375, 667 });
    CGContextFillPath(context);
    
    // draw to the screen
    // FSOCIETY #MrRobot
    CGContextSetFillColor(context, (CGFloat []) { 1, 0, 0, 1 });
    // F
    CGContextAddRect(context, (struct CGRect) { 20, 20, 100, 30 });
    CGContextAddRect(context, (struct CGRect) { 20, 20, 30, 150});
    CGContextAddRect(context, (struct CGRect) { 20, 75, 80, 30});
    // S
    CGContextAddRect(context, (struct CGRect) { 20, 190, 50, 30 });
    CGContextAddRect(context, (struct CGRect) { 20, 190, 30, 60});
    CGContextAddRect(context, (struct CGRect) { 20, 245, 50, 30});
    CGContextAddRect(context, (struct CGRect) { 20, 190, 30, 60});
    CGContextAddRect(context, (struct CGRect) { 40, 245, 30, 60});
    CGContextAddRect(context, (struct CGRect) { 20, 300, 50, 30});
    // O
    CGContextAddRect(context, (struct CGRect) { 80, 190, 50, 30 });
    CGContextAddRect(context, (struct CGRect) { 80, 190, 20, 100 });
    CGContextAddRect(context, (struct CGRect) { 80, 270, 50, 30 });
    CGContextAddRect(context, (struct CGRect) { 120, 190, 20, 110 });
    // C
    CGContextAddRect(context, (struct CGRect) { 150, 190, 50, 30 });
    CGContextAddRect(context, (struct CGRect) { 150, 190, 20, 100 });
    CGContextAddRect(context, (struct CGRect) { 150, 270, 50, 30 });
    // I
    CGContextAddRect(context, (struct CGRect) { 210, 190, 20, 110 });
    // E
    CGContextAddRect(context, (struct CGRect) { 240, 190, 20, 110 });
    CGContextAddRect(context, (struct CGRect) { 240, 190, 50, 20 });
    CGContextAddRect(context, (struct CGRect) { 240, 235, 50, 20 });
    CGContextAddRect(context, (struct CGRect) { 240, 280, 50, 20 });
    // T
    CGContextAddRect(context, (struct CGRect) { 20, 350, 50, 20 });
    CGContextAddRect(context, (struct CGRect) { 35, 350, 20, 70 });
    // Y
    CGContextAddRect(context, (struct CGRect) { 75, 340, 20, 30 });
    CGContextAddRect(context, (struct CGRect) { 105, 340, 20, 30 });
    CGContextAddRect(context, (struct CGRect) { 75, 370, 50, 20 });
    CGContextAddRect(context, (struct CGRect) { 90, 370, 20, 50 });
    CGContextFillPath(context);
}


__attribute__((constructor))
static void initView()
{
    // create subclass of view and uiview
    ViewClass = objc_allocateClassPair((Class) objc_getClass("UIView"), "View", 0);
    
    // add -drawRect:
    class_addMethod(ViewClass, sel_getUid("drawRect:"), (IMP) View_drawRect, "v@:");
    
    objc_registerClassPair(ViewClass);
}
