#include <test.h>
JNIEXPORT jstring JNICALL Java_org_witsoft_myapplication_MainActivity_helloJni
        (JNIEnv *env, jclass jobj) {
    return (*env)->NewStringUTF(env,"Hello JNI!");
}

JNIEXPORT jint JNICALL Java_org_witsoft_myapplication_MainActivity_addCalc
        (JNIEnv *env, jclass jobj, jint ja, jint jb) {
    return ja + jb;
}