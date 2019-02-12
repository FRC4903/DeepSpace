#include <jni.h>

static JavaVM* jvm = nullptr;

namespace sim {
jint SimOnLoad(JavaVM* vm, void* reserved) {
  jvm = vm;

  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    return JNI_ERR;

  return JNI_VERSION_1_6;
}

void SimOnUnload(JavaVM * vm, void* reserved) {
  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    return;
  jvm = nullptr;
}
}

static void ThrowSimException(JNIEnv* env) {

}

extern "C" {
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_registerTriggerLowerBoundCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_cancelTriggerLowerBoundCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_getTriggerLowerBound(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_setTriggerLowerBound(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_registerTriggerUpperBoundCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_cancelTriggerUpperBoundCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_getTriggerUpperBound(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_setTriggerUpperBound(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogTriggerDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_registerVoltageCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_cancelVoltageCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_getVoltage(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_setVoltage(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogOutDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_registerAngleCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_cancelAngleCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_getAngle(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_setAngle(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_registerRateCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_cancelRateCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_getRate(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_setRate(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogGyroDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerFPGAButtonCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelFPGAButtonCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getFPGAButton(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setFPGAButton(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerVInVoltageCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelVInVoltageCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getVInVoltage(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setVInVoltage(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerVInCurrentCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelVInCurrentCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getVInCurrent(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setVInCurrent(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserVoltage6VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserVoltage6VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserVoltage6V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserVoltage6V(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserCurrent6VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserCurrent6VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserCurrent6V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserCurrent6V(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserActive6VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserActive6VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserActive6V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserActive6V(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserVoltage5VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserVoltage5VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserVoltage5V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserVoltage5V(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserCurrent5VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserCurrent5VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserCurrent5V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserCurrent5V(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserActive5VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserActive5VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserActive5V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserActive5V(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserVoltage3V3Callback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserVoltage3V3Callback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserVoltage3V3(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserVoltage3V3(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserCurrent3V3Callback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserCurrent3V3Callback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserCurrent3V3(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserCurrent3V3(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserActive3V3Callback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserActive3V3Callback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserActive3V3(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserActive3V3(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserFaults6VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserFaults6VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserFaults6V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserFaults6V(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserFaults5VCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserFaults5VCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserFaults5V(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserFaults5V(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_registerUserFaults3V3Callback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_cancelUserFaults3V3Callback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_getUserFaults3V3(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_setUserFaults3V3(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RoboRioDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_registerReadCallback(JNIEnv * env, jclass, jint, jobject) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_cancelReadCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_registerWriteCallback(JNIEnv * env, jclass, jint, jobject) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_cancelWriteCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_registerReadAutoReceiveBufferCallback(JNIEnv * env, jclass, jint, jobject) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_cancelReadAutoReceiveBufferCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_registerReadCallback(JNIEnv * env, jclass, jint, jobject) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_cancelReadCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_registerWriteCallback(JNIEnv * env, jclass, jint, jobject) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_cancelWriteCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_I2CDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_registerValueCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_cancelValueCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_getValue(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_setValue(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_registerPulseLengthCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_cancelPulseLengthCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_getPulseLength(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_setPulseLength(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_registerIsInputCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_cancelIsInputCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_getIsInput(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_setIsInput(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_registerFilterIndexCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_cancelFilterIndexCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_getFilterIndex(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_setFilterIndex(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DIODataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerInitializedForwardCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelInitializedForwardCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getInitializedForward(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setInitializedForward(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerInitializedReverseCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelInitializedReverseCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getInitializedReverse(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setInitializedReverse(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerForwardCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelForwardCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getForward(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setForward(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerReverseCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelReverseCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getReverse(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setReverse(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_registerTemperatureCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_cancelTemperatureCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_getTemperature(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_setTemperature(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_registerVoltageCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_cancelVoltageCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_getVoltage(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_setVoltage(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_registerCurrentCallback(JNIEnv * env, jclass, jint, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_cancelCurrentCallback(JNIEnv * env, jclass, jint, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_getCurrent(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_setCurrent(JNIEnv * env, jclass, jint, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PDPDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_registerActiveCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_cancelActiveCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_getActive(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_setActive(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_registerRangeCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_cancelRangeCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_getRange(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_setRange(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_registerXCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_cancelXCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_getX(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_setX(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_registerYCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_cancelYCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_getY(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_setY(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_registerZCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_cancelZCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_getZ(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_setZ(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SPIAccelerometerDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerSolenoidInitializedCallback(JNIEnv * env, jclass, jint, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelSolenoidInitializedCallback(JNIEnv * env, jclass, jint, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getSolenoidInitialized(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setSolenoidInitialized(JNIEnv * env, jclass, jint, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerSolenoidOutputCallback(JNIEnv * env, jclass, jint, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelSolenoidOutputCallback(JNIEnv * env, jclass, jint, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getSolenoidOutput(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setSolenoidOutput(JNIEnv * env, jclass, jint, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerCompressorInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelCompressorInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getCompressorInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setCompressorInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerCompressorOnCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelCompressorOnCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getCompressorOn(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setCompressorOn(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerClosedLoopEnabledCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelClosedLoopEnabledCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getClosedLoopEnabled(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setClosedLoopEnabled(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerPressureSwitchCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelPressureSwitchCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getPressureSwitch(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setPressureSwitch(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerCompressorCurrentCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_cancelCompressorCurrentCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_getCompressorCurrent(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_setCompressorCurrent(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerAllNonSolenoidCallbacks(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_registerAllSolenoidCallbacks(JNIEnv * env, jclass, jint, jint, jobject, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PCMDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_registerActiveCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_cancelActiveCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_getActive(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_setActive(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_registerRangeCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_cancelRangeCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_getRange(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_setRange(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_registerXCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_cancelXCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_getX(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_setX(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_registerYCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_cancelYCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_getY(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_setY(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_registerZCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_cancelZCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_getZ(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_setZ(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AccelerometerDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerEnabledCallback(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_cancelEnabledCallback(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_getEnabled(JNIEnv * env, jclass) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setEnabled(JNIEnv * env, jclass, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerAutonomousCallback(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_cancelAutonomousCallback(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_getAutonomous(JNIEnv * env, jclass) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setAutonomous(JNIEnv * env, jclass, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerTestCallback(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_cancelTestCallback(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_getTest(JNIEnv * env, jclass) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setTest(JNIEnv * env, jclass, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerEStopCallback(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_cancelEStopCallback(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_getEStop(JNIEnv * env, jclass) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setEStop(JNIEnv * env, jclass, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerFmsAttachedCallback(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_cancelFmsAttachedCallback(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_getFmsAttached(JNIEnv * env, jclass) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setFmsAttached(JNIEnv * env, jclass, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerDsAttachedCallback(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_cancelDsAttachedCallback(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_getDsAttached(JNIEnv * env, jclass) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setDsAttached(JNIEnv * env, jclass, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setJoystickAxes(JNIEnv * env, jclass, jbyte, jfloatArray) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setJoystickPOVs(JNIEnv * env, jclass, jbyte, jshortArray) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setJoystickButtons(JNIEnv * env, jclass, jbyte, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_setMatchInfo(JNIEnv * env, jclass, jstring, jstring, jint, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_registerAllCallbacks(JNIEnv * env, jclass, jobject, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_notifyNewData(JNIEnv * env, jclass) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DriverStationDataJNI_resetData(JNIEnv * env, jclass) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerAverageBitsCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelAverageBitsCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getAverageBits(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setAverageBits(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerOversampleBitsCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelOversampleBitsCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getOversampleBits(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setOversampleBits(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerVoltageCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelVoltageCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getVoltage(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setVoltage(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerAccumulatorInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelAccumulatorInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getAccumulatorInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setAccumulatorInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerAccumulatorValueCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelAccumulatorValueCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jlong JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getAccumulatorValue(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setAccumulatorValue(JNIEnv * env, jclass, jint, jlong) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerAccumulatorCountCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelAccumulatorCountCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jlong JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getAccumulatorCount(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setAccumulatorCount(JNIEnv * env, jclass, jint, jlong) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerAccumulatorCenterCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelAccumulatorCenterCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getAccumulatorCenter(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setAccumulatorCenter(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_registerAccumulatorDeadbandCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_cancelAccumulatorDeadbandCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_getAccumulatorDeadband(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_setAccumulatorDeadband(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_AnalogInDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerCountCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelCountCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getCount(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setCount(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerPeriodCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelPeriodCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getPeriod(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setPeriod(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerResetCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelResetCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getReset(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setReset(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerMaxPeriodCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelMaxPeriodCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getMaxPeriod(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setMaxPeriod(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerDirectionCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelDirectionCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getDirection(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setDirection(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerReverseDirectionCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelReverseDirectionCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getReverseDirection(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setReverseDirection(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_registerSamplesToAverageCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_cancelSamplesToAverageCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_getSamplesToAverage(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_setSamplesToAverage(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_EncoderDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SimulatorJNI_waitForProgramStart(JNIEnv * env, jclass) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SimulatorJNI_setProgramStarted(JNIEnv * env, jclass) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SimulatorJNI_restartTiming(JNIEnv * env, jclass) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_SimulatorJNI_resetHandles(JNIEnv * env, jclass) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_registerRawValueCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_cancelRawValueCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_getRawValue(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_setRawValue(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_registerSpeedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_cancelSpeedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_getSpeed(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_setSpeed(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_registerPositionCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_cancelPositionCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_getPosition(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_setPosition(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_registerPeriodScaleCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_cancelPeriodScaleCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_getPeriodScale(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_setPeriodScale(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_registerZeroLatchCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_cancelZeroLatchCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_getZeroLatch(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_setZeroLatch(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_PWMDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_registerInitializedCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_cancelInitializedCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_getInitialized(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_setInitialized(JNIEnv * env, jclass, jint, jboolean) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_registerDutyCycleCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_cancelDutyCycleCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_getDutyCycle(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_setDutyCycle(JNIEnv * env, jclass, jint, jdouble) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_registerPinCallback(JNIEnv * env, jclass, jint, jobject, jboolean) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_cancelPinCallback(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_getPin(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
  return 0;
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_setPin(JNIEnv * env, jclass, jint, jint) {
  ThrowSimException(env);
}
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_mockdata_DigitalPWMDataJNI_resetData(JNIEnv * env, jclass, jint) {
  ThrowSimException(env);
}
}
