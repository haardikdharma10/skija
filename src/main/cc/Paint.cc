#include <iostream>
#include <jni.h>
#include "SkPaint.h"
#include "SkShader.h"
#include "SkImageFilter.h"
#include "SkPathEffect.h"

static void deletePaint(SkPaint* paint) {
    // std::cout << "Deleting [SkPaint " << paint << "]" << std::endl;
    delete paint;
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skija_Paint_nInit(JNIEnv* env, jclass jclass) {
    SkPaint* obj = new SkPaint();
    obj->setAntiAlias(true);
    return reinterpret_cast<jlong>(obj);
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skija_Paint_nGetNativeFinalizer(JNIEnv* env, jclass jclass) {
    return static_cast<jlong>(reinterpret_cast<uintptr_t>(&deletePaint));
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_jetbrains_skija_Paint_nIsAntiAlias(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return instance->isAntiAlias();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetAntiAlias(JNIEnv* env, jclass jclass, jlong ptr, jboolean value) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setAntiAlias(value);
}

extern "C" JNIEXPORT jint JNICALL Java_org_jetbrains_skija_Paint_nGetColor(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return instance->getColor();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetColor(JNIEnv* env, jclass jclass, jlong ptr, jint color) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setColor(color);
}

extern "C" JNIEXPORT jint JNICALL Java_org_jetbrains_skija_Paint_nGetStyle(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return static_cast<jlong>(instance->getStyle());
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetStyle(JNIEnv* env, jclass jclass, jlong ptr, jint style) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setStyle(static_cast<SkPaint::Style>(style));
}

extern "C" JNIEXPORT jfloat JNICALL Java_org_jetbrains_skija_Paint_nGetStrokeWidth(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return instance->getStrokeWidth();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetStrokeWidth(JNIEnv* env, jclass jclass, jlong ptr, jfloat width) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setStrokeWidth(width);
}

extern "C" JNIEXPORT jfloat JNICALL Java_org_jetbrains_skija_Paint_nGetStrokeMiter(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return instance->getStrokeMiter();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetStrokeMiter(JNIEnv* env, jclass jclass, jlong ptr, jfloat miter) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setStrokeMiter(miter);
}

extern "C" JNIEXPORT jint JNICALL Java_org_jetbrains_skija_Paint_nGetStrokeCap(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return static_cast<jlong>(instance->getStrokeCap());
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetStrokeCap(JNIEnv* env, jclass jclass, jlong ptr, jint cap) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setStrokeCap(static_cast<SkPaint::Cap>(cap));
}

extern "C" JNIEXPORT jint JNICALL Java_org_jetbrains_skija_Paint_nGetStrokeJoin(JNIEnv* env, jclass jclass, jlong ptr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    return static_cast<jlong>(instance->getStrokeJoin());
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetStrokeJoin(JNIEnv* env, jclass jclass, jlong ptr, jint join) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setStrokeJoin(static_cast<SkPaint::Join>(join));
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetImageFilter(JNIEnv* env, jclass jclass, jlong ptr, jlong filterPtr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    SkImageFilter* filter = reinterpret_cast<SkImageFilter*>(static_cast<uintptr_t>(filterPtr));
    instance->setImageFilter(sk_ref_sp<SkImageFilter>(filter));
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetBlendMode(JNIEnv* env, jclass jclass, jlong ptr, jint mode) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    instance->setBlendMode(static_cast<SkBlendMode>(mode));
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetPathEffect(JNIEnv* env, jclass jclass, jlong ptr, jlong pathEffectPtr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    SkPathEffect* pathEffect = reinterpret_cast<SkPathEffect*>(static_cast<uintptr_t>(pathEffectPtr));
    instance->setPathEffect(sk_ref_sp(pathEffect));
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skija_Paint_nSetShader(JNIEnv* env, jclass jclass, jlong ptr, jlong shaderPtr) {
    SkPaint* instance = reinterpret_cast<SkPaint*>(static_cast<uintptr_t>(ptr));
    SkShader* shader = reinterpret_cast<SkShader*>(static_cast<uintptr_t>(shaderPtr));
    instance->setShader(sk_ref_sp<SkShader>(shader));
}