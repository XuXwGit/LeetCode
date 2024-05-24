#ifndef _EXAMINATION_EXAMINATION_H_
#define _EXAMINATION_EXAMINATION_H_

#include "examination/0410_Huawei/test_HW_0410.h"
#include "examination/0417_Huawei/test_HW_0417.h"
#include "examination/0424_Huawei/test_HW_0424.h"
#include "examination/0508_Huawei/test_HW_0508.h"
#include "examination/0515_Huawei/test_HW_0515.h"
#include "examination/0522_Huawei/test_HW_0522.h"

void test_examination(){
    cout << " ==== test examination ==== " << endl;
    test_HW_0410();
    test_HW_0417();
    test_HW_0424();
    test_HW_0508();
    test_HW_0515();
    test_HW_0522();
}

#endif // _EXAMINATION_EXAMINATION_H_