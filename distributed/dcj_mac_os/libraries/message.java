/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class message {
  public static int NumberOfNodes() {
    return messageJNI.NumberOfNodes();
  }

  public static int MyNodeId() {
    return messageJNI.MyNodeId();
  }

  public static void PutChar(int target, char value) {
    messageJNI.PutChar(target, value);
  }

  public static void PutInt(int target, int value) {
    messageJNI.PutInt(target, value);
  }

  public static void PutLL(int target, long value) {
    messageJNI.PutLL(target, value);
  }

  public static void Send(int target) {
    messageJNI.Send(target);
  }

  public static int Receive(int source) {
    return messageJNI.Receive(source);
  }

  public static char GetChar(int source) {
    return messageJNI.GetChar(source);
  }

  public static int GetInt(int source) {
    return messageJNI.GetInt(source);
  }

  public static long GetLL(int source) {
    return messageJNI.GetLL(source);
  }

}
