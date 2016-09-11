//linkedlist.m
//Patrick Anderson psa5dg
//Lab 105
//5/3/16

#import <stdio.h>
#import <stdlib.h>
#import <Foundation/NSObject.h>


@interface ListNode : NSObject {
@private
   int val;
   ListNode *next;
}
- (id) val: (int) val_value;
- (int) val;
- (id) next: (ListNode*) next_value;
- (ListNode*) next;
@end


@implementation ListNode

- (id) val: (int) val_value {
  val = val_value;
  return self;
}
- (int) val {
  return val;
}
- (id) next: (ListNode*) next_value {
  next = next_value;
  return self;
}
- (ListNode*) next {
  return next;
}

@end



int main() {
  int n = 0;
  ListNode *head = [ListNode new];
  ListNode *start = head;
  
  printf("Enter how many values to input: ");
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    printf("Enter value %d: ", i+1);
    int v = 0;
    scanf("%d", &v);
    ListNode *node = [ListNode new];
    [node val: v];
    [start next: node];
    start = [start next];
  }
  start = head;
  for(int i = 0; i < n; i++) {
    start = [start next];
    printf("%d \n", [start val]);
  }

  start = head;
  while(start != nil) {
    ListNode *temp = start;
    start = [start next];
    [temp release];
  }
  start = nil;
  head = nil;
  return 0;
}
