//
//  ViewUtils.h
//
//  Version 1.1.2
//
//  Created by Nick Lockwood on 19/11/2011.
//  Copyright (c) 2011 Charcoal Design
//
//  Distributed under the permissive zlib License
//  Get the latest version from here:
//
//  https://github.com/nicklockwood/ViewUtils
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//


#import <UIKit/UIKit.h>

@interface UIView (ViewUtils)


//这种方法从nib文件加载视图。加载视图必须是文件中的第一个对象。该方法用于加载视图如uitableviewcell池,或iCarousel项视图。nib文件缓存,所以subequent负载会表现的更好。
+ (id)instanceWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)bundleOrNil owner:(id)owner;

//这种方法类似于“instanceWithNibName:”,而是返回第一个视图的nib文件,这个方法加载视图,然后将它作为子视图添加到视图的方法被调用时,调整加载视图,以适应在父视图的范围,如果必要的。这是特别有用如果你想创建一个复杂的视图组成的可重用的子视图,每个存储在自己的nib文件。
- (void)loadContentsWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)bundleOrNil;


//返回第一个匹配的子视图的视图本身指定的谓词。如果没有匹配的子视图,方法返回零。
- (UIView *)viewMatchingPredicate:(NSPredicate *)predicate;
//返回第一子视图的视图本身指定的标签值,*和*指定的类。这是比普通的viewWithTag:安全方法。
- (UIView *)viewWithTag:(NSInteger)tag ofClass:(Class)viewClass;
//返回第一子视图的视图本身指定的类。
- (UIView *)viewOfClass:(Class)viewClass;

//这些方法的工作就像单一视图的同龄人,而是返回匹配的第一个观点,他们返回所有匹配的看法。以深度优先的方式执行搜索。
- (NSArray *)viewsMatchingPredicate:(NSPredicate *)predicate;
- (NSArray *)viewsWithTag:(NSInteger)tag;
- (NSArray *)viewsWithTag:(NSInteger)tag ofClass:(Class)viewClass;
- (NSArray *)viewsOfClass:(Class)viewClass;

//这些方法的工作像viewMatching / /宽度版本,但工作* *视图层次,而不是下来会返回第一个匹配的父视图指定标准。
- (UIView *)firstSuperviewMatchingPredicate:(NSPredicate *)predicate;
- (UIView *)firstSuperviewOfClass:(Class)viewClass;
- (UIView *)firstSuperviewWithTag:(NSInteger)tag;
- (UIView *)firstSuperviewWithTag:(NSInteger)tag ofClass:(Class)viewClass;

//该方法返回是的如果视图,或任何父视图在链中的匹配标准。这对事件处理非常有用,例如,如果你想知道如果一个给定的接触或在给定控制或控制类型,例如你可以忽略手势上执行特定的视图。
- (BOOL)viewOrAnySuperviewMatchesPredicate:(NSPredicate *)predicate;
- (BOOL)viewOrAnySuperviewIsKindOfClass:(Class)viewClass;

//这些方法允许您确定另一个视图的视图是一个孩子。这些方法将搜索整个父视图链,不仅仅是一个水平,如果一个视图的父视图的父视图* *是另一个,它仍然会返回YES。
- (BOOL)isSuperviewOfView:(UIView *)view;
- (BOOL)isSubviewOfView:(UIView *)view;

//这种方法使用响应者链识别的第一个视图控制器负责视图控制器链。举个例子,如果一个按钮上调用这个方法时,它将返回主机的视图控制器的视图,其中包含按钮。
- (UIViewController *)firstViewController;

//该方法返回第一响应者如果是视图的子视图的方法被调用时,或者如果不是零。如果你不知道子树第一响应者可能位于,调用该方法在主窗口或当前frontmost视图的根视图控制器应该返回所需的结果。
- (UIView *)firstResponder;

//frame accessors

@property (nonatomic, assign) CGPoint origin;//视图的位置在父视图的起源(左上角)。这相当于“view.frame.origin”。
@property (nonatomic, assign) CGSize size;//的外维度视图。这相当于“view.frame.size”. .

//四个角的位置在父视图的视图。这些职位都是相对于父视图左上角的,(例如)的观点。底部的财产相当于”视图。+ view.height '。
@property (nonatomic, assign) CGFloat top;
@property (nonatomic, assign) CGFloat left;
@property (nonatomic, assign) CGFloat bottom;
@property (nonatomic, assign) CGFloat right;

//的外维度视图。这些都是相当于“view.size。宽度”和“view.size。高度的分别。
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

//锚点的位置为视图在父视图(通常是中心)。这些equivqlent view.center。x”和“view.center。分别y '。
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;

//bounds accessors
//视图边界的尺寸(内尺寸)。范围大小是有用的观点已经改变了,你可以不再依靠帧大小尺寸准确获取或设置内容。
@property (nonatomic, assign) CGSize boundsSize;
@property (nonatomic, assign) CGFloat boundsWidth;
@property (nonatomic, assign) CGFloat boundsHeight;

//content getters
//经常你希望的位置完全填满它的父视图的子视图,但是为了做到这一点你必须contruct CGRect中与父视图的宽度和高度的界限和起源的0,0。不幸的是没有保证的父视图。范围将有一个起源0,0因为在ui窗口,旋转,或UIScrollView滚动和缩放,边界的起源已经改变了为了正确对齐视图内的内容框架。contentBounds属性返回一个匹配的矩形边界大小,但总是有一个起源0,0。
@property (nonatomic, readonly) CGRect contentBounds;

//通常你希望它的父视图的子视图在确切的中心位置,但计算的中心观点是一段冗长的代码编写。contentCenter属性返回这个职位。
@property (nonatomic, readonly) CGPoint contentCenter;

//additional frame setters

//通常的设置左右两个边的一个视图,或设置宽度不影响右手边,因为属性是有联系的。这些setter方法使它更容易通过允许您设置这两个属性与单个方法调用。
- (void)setLeft:(CGFloat)left right:(CGFloat)right;
- (void)setWidth:(CGFloat)width right:(CGFloat)right;
- (void)setTop:(CGFloat)top bottom:(CGFloat)bottom;
- (void)setHeight:(CGFloat)height bottom:(CGFloat)bottom;

//animation
//这些方法使用核心动画执行交叉渐变过渡的指定的持续时间。一个淡入淡出常常是有用的,如果你想动画一些视图的变化属性已经不支持动画。一个典型示例是改变文本UIImageView UILabel或图像。
- (void)crossfadeWithDuration:(NSTimeInterval)duration;
- (void)crossfadeWithDuration:(NSTimeInterval)duration completion:(void (^)(void))completion;

@end

