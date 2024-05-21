/*
柜式路由器需要配备接口板才可以工作,接口板用于接入用户业务，且接口板转发能力的和不能大于路由器整机的转发能力。当前某客户订购了2台设备和num块接口板。请计算是否存在一种安装方法，使用户选购的接口板，刚好能装到两台设备上，且每台设备配置的口板的转发能力之和,刚好和整机的转发能力相等。

 1、设备整机转发能力的单位是Gbps,Gbps是设备单位时间内传输的比特数，代表千兆比特/秒。为了简化问题,规定值为整数,范围为[1,2000]。

 2、客户订购的接口板数量num,值的范围[1,200]。

 3、接口板容量的单位也是Gbps，比如1010 40 40 100，代表选购了5块接口板,转发能力分别是10Gbps, 10Gbps, 40Gbps, 40Gbps, 100Gbps，接口板转发能力的范围一般为特定枚举值，为了简化问题，规定值为正整数。

输入描述
第一行是目标设备的转发能力。第二行是客户订购的接口板数量num 。第三行是订购的包含num个接口板的转发能力的列表。

输出描述
如果存在满足要求的安装方法，请分两行输出两台设备配置的接口板的转发能力的列表，且要求每台设备的单板，按转发能力从小到大排列。两台设备的单板，第一个单板转发能力小的优先输出。如果第一个单板转发能力相同，那单板数多的优先输出。如果不存在对应的安装方案，则返回-1。用例保证在满足前面条件的情况下，不会有多种不同的结果。
*/

#ifndef _EXAMINATION_HUAWEI_0515_SEPRATE_H_
#define _EXAMINATION_HUAWEI_0515_SEPRATE_H_




#endif // _EXAMINATION_HUAWEI_0515_SEPRATE_H_