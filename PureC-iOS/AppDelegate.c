//
//  AppDelegate.m
//  PureC-iOS
//
//  Created by Faris Sbahi on 11/22/16.
//
#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreGraphics/CoreGraphics.h>

// This is equivalent to creating a @class with one public variable named 'window'.
struct AppDel
{
    Class isa;
    
    id window;
};

// equiv to  [AppDelegate class]
Class AppDelClass;

// equiv to -application:didFinishLaunchingWithOptions:

BOOL AppDel_didFinishLaunching(struct AppDel *self, SEL _cmd, void *application, void *options)
{
    // +alloc & -initWithFrame: window
    // sel-getUid equiv to @selector
    self->window = objc_msgSend(objc_getClass("UIWindow"), sel_getUid("alloc"));
    self->window = objc_msgSend(self->window, sel_getUid("initWithFrame:"), (struct CGRect) { 0, 0, 375, 667 });
    
    // create VC
    id viewController = objc_msgSend(objc_msgSend(objc_getClass("UIViewController"), sel_getUid("alloc")), sel_getUid("init"));
    
    // define screen bounds
    id view = objc_msgSend(objc_msgSend(objc_getClass("View"), sel_getUid("alloc")), sel_getUid("initWithFrame:"), (struct CGRect) { 0, 0, 375, 667 });
    
    // add view to VC and VC to window
    objc_msgSend(objc_msgSend(viewController, sel_getUid("view")), sel_getUid("addSubview:"), view);
    objc_msgSend(self->window, sel_getUid("setRootViewController:"), viewController);
    
    // show window
    objc_msgSend(self->window, sel_getUid("makeKeyAndVisible"));
    
    return YES;
}

__attribute__((constructor))
static void initAppDel()
{
    AppDelClass = objc_allocateClassPair((Class) objc_getClass("UIResponder"), "AppDelegate", 0);
    
    class_addIvar(AppDelClass, "window", sizeof(id), 0, "@");
    
    // link -application:didFinishLaunchingWithOptions:
    class_addMethod(AppDelClass, sel_getUid("application:didFinishLaunchingWithOptions:"), (IMP) AppDel_didFinishLaunching, "i@:@@");
    
    objc_registerClassPair(AppDelClass);
}
