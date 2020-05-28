#include <test.h>
#include <android/log.h>

JNIEXPORT jstring JNICALL aa
        (JNIEnv *env, jclass jobj) {
    return env->NewStringUTF("Hello JNI2!");
}

static JNINativeMethod methods[] = {
        {"helloJni", "()Ljava/lang/String;", reinterpret_cast<void*>(aa)}
};

//JNIEXPORT jstring JNICALL Java_org_witsoft_myapplication_MainActivity_helloJni
//        (JNIEnv *env, jclass jobj) {
//    return env->NewStringUTF("Hello JNI!");
//}

JNIEXPORT jint JNICALL Java_org_witsoft_myapplication_MainActivity_addCalc
        (JNIEnv *env, jclass jobj, jint ja, jint jb) {
    return ja + jb;
}
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv* env;
    __android_log_print(ANDROID_LOG_INFO, "native", "JNI_OnUnload");
    if (JNI_OK != vm->GetEnv(reinterpret_cast<void**> (&env),JNI_VERSION_1_4)) {
        __android_log_print(ANDROID_LOG_INFO, "native", "JNI_OnLoad could not get JNI env");
        return JNI_ERR;
    }
    jclass clazz = env->FindClass("org/witsoft/myapplication/MainActivity");
    //注册Native方法
    if (env->RegisterNatives(clazz, methods, sizeof(methods)/sizeof((methods)[0])) < 0) {
        __android_log_print(ANDROID_LOG_INFO, "native","RegisterNatives error");
        return JNI_ERR;
    }
    return JNI_VERSION_1_4;
}