#!/usr/bin/env bpftrace
#include <linux/kernel.h>
#include <asm/unistd.h>
// struct MyStruct {
//     unsigned long sct[300];      
// }
// $s = (struct MyStruct *) arg0;

BEGIN
{
	printf("trace syscalls to detect LKM-Rootkit ...... Hit Ctrl-C to end.\n");
    // @nr_syscall = kaddr("NR_syscalls");
    // printf("NR_syscalls is %p \n",@nr_syscall);
    // printf("    sys_call_table is %p    ",*(@sys_call_table)+$i*8); *(((uint64)@sys_call_table)+(uint64)$i*8) 
        // printf("%s \n",ksym(   *(*((uint64)@sys_call_table)+(uint64)$i*64)  ));
//--------------------------------------------------------------------------------------------------------------    
    @sys_call_table = kaddr("sys_call_table");
    // printf("sys_call_table is %p \n",@sys_call_table);  
    $a = (uint64)@sys_call_table - (uint64)0x1000000;
    $b = (uint64)@sys_call_table + (uint64)0x1000000;
    $i = 0; 
    while ($i <= 335) { 
        // printf("%d ", $i);  
        // printf("    sys_call_table[%d] is %p    ",$i,*(((uint64)@sys_call_table)+(uint64)$i*8)); 
        // printf("%s \n",ksym(*(((uint64)@sys_call_table)+(uint64)$i*8) ));
        $addr = (uint64)*(((uint64)@sys_call_table)+(uint64)$i*8);
        if((uint64)$addr<(uint64)$a || (uint64)$addr>(uint64)$b){
            printf("+++++++++++ sys_call_table[%d] is be hooked ++++++++++++++++ \n",$i);
        }

        $i++}
    exit();
    // @sys_getdents64 = kaddr("sys_getdents64");      // ---找不到
    // printf("sys_getdents64 is %p \n",@sys_getdents64); 
    // @flag = 0;

}

// kprobe:__x64_sys_kill
// kprobe:__x64_sys_getdents64
// {
//     if(@flag == 0){
//        printf("++++++    __x64_sys_getdents64 maybe hooked   "); 
//        @flag =0;
//     }
//     @flag =0;
//     printf("++++++    __x64_sys_getdents64 is %p    ",reg("ip"));
//     printf("%s\n", ksym(reg("ip")));
// }

// tracepoint:syscalls:sys_enter_getdents64
// {
//     printf("+++++++++++    tracepoint sys_enter_getdents64 __     \n");
//     @flag =1;


// }

END
{
    clear(@sys_call_table);
}
