/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class aiNodeAnimVector : IDisposable, System.Collections.IEnumerable
#if !SWIG_DOTNET_1
    , System.Collections.Generic.IList<aiNodeAnim>
#endif
 {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal aiNodeAnimVector(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(aiNodeAnimVector obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~aiNodeAnimVector() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_aiNodeAnimVector(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public aiNodeAnimVector(System.Collections.ICollection c) : this() {
    if (c == null)
      throw new ArgumentNullException("c");
    foreach (aiNodeAnim element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public aiNodeAnim this[int index]  {
    get {
      return getitem(index);
    }
    set {
      setitem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)capacity();
    }
    set {
      if (value < size())
        throw new ArgumentOutOfRangeException("Capacity");
      reserve((uint)value);
    }
  }

  public int Count {
    get {
      return (int)size();
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

#if SWIG_DOTNET_1
  public void CopyTo(System.Array array)
#else
  public void CopyTo(aiNodeAnim[] array)
#endif
  {
    CopyTo(0, array, 0, this.Count);
  }

#if SWIG_DOTNET_1
  public void CopyTo(System.Array array, int arrayIndex)
#else
  public void CopyTo(aiNodeAnim[] array, int arrayIndex)
#endif
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

#if SWIG_DOTNET_1
  public void CopyTo(int index, System.Array array, int arrayIndex, int count)
#else
  public void CopyTo(int index, aiNodeAnim[] array, int arrayIndex, int count)
#endif
  {
    if (array == null)
      throw new ArgumentNullException("array");
    if (index < 0)
      throw new ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(getitemcopy(index+i), arrayIndex+i);
  }

#if !SWIG_DOTNET_1
  System.Collections.Generic.IEnumerator<aiNodeAnim> System.Collections.Generic.IEnumerable<aiNodeAnim>.GetEnumerator() {
    return new aiNodeAnimVectorEnumerator(this);
  }
#endif

  System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() {
    return new aiNodeAnimVectorEnumerator(this);
  }

  public aiNodeAnimVectorEnumerator GetEnumerator() {
    return new aiNodeAnimVectorEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class aiNodeAnimVectorEnumerator : System.Collections.IEnumerator
#if !SWIG_DOTNET_1
    , System.Collections.Generic.IEnumerator<aiNodeAnim>
#endif
  {
    private aiNodeAnimVector collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public aiNodeAnimVectorEnumerator(aiNodeAnimVector collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public aiNodeAnim Current {
      get {
        if (currentIndex == -1)
          throw new InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new InvalidOperationException("Collection modified.");
        return (aiNodeAnim)currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new InvalidOperationException("Collection modified.");
      }
    }

#if !SWIG_DOTNET_1
    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
#endif
  }

  public void Clear() {
    AssimpPINVOKE.aiNodeAnimVector_Clear(swigCPtr);
  }

  public void Add(aiNodeAnim x) {
    AssimpPINVOKE.aiNodeAnimVector_Add(swigCPtr, aiNodeAnim.getCPtr(x));
  }

  private uint size() {
    uint ret = AssimpPINVOKE.aiNodeAnimVector_size(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = AssimpPINVOKE.aiNodeAnimVector_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    AssimpPINVOKE.aiNodeAnimVector_reserve(swigCPtr, n);
  }

  public aiNodeAnimVector() : this(AssimpPINVOKE.new_aiNodeAnimVector__SWIG_0(), true) {
  }

  public aiNodeAnimVector(aiNodeAnimVector other) : this(AssimpPINVOKE.new_aiNodeAnimVector__SWIG_1(aiNodeAnimVector.getCPtr(other)), true) {
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public aiNodeAnimVector(int capacity) : this(AssimpPINVOKE.new_aiNodeAnimVector__SWIG_2(capacity), true) {
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  private aiNodeAnim getitemcopy(int index) {
    IntPtr cPtr = AssimpPINVOKE.aiNodeAnimVector_getitemcopy(swigCPtr, index);
    aiNodeAnim ret = (cPtr == IntPtr.Zero) ? null : new aiNodeAnim(cPtr, false);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private aiNodeAnim getitem(int index) {
    IntPtr cPtr = AssimpPINVOKE.aiNodeAnimVector_getitem(swigCPtr, index);
    aiNodeAnim ret = (cPtr == IntPtr.Zero) ? null : new aiNodeAnim(cPtr, false);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, aiNodeAnim val) {
    AssimpPINVOKE.aiNodeAnimVector_setitem(swigCPtr, index, aiNodeAnim.getCPtr(val));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(aiNodeAnimVector values) {
    AssimpPINVOKE.aiNodeAnimVector_AddRange(swigCPtr, aiNodeAnimVector.getCPtr(values));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public aiNodeAnimVector GetRange(int index, int count) {
    IntPtr cPtr = AssimpPINVOKE.aiNodeAnimVector_GetRange(swigCPtr, index, count);
    aiNodeAnimVector ret = (cPtr == IntPtr.Zero) ? null : new aiNodeAnimVector(cPtr, true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, aiNodeAnim x) {
    AssimpPINVOKE.aiNodeAnimVector_Insert(swigCPtr, index, aiNodeAnim.getCPtr(x));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, aiNodeAnimVector values) {
    AssimpPINVOKE.aiNodeAnimVector_InsertRange(swigCPtr, index, aiNodeAnimVector.getCPtr(values));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    AssimpPINVOKE.aiNodeAnimVector_RemoveAt(swigCPtr, index);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    AssimpPINVOKE.aiNodeAnimVector_RemoveRange(swigCPtr, index, count);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public static aiNodeAnimVector Repeat(aiNodeAnim value, int count) {
    IntPtr cPtr = AssimpPINVOKE.aiNodeAnimVector_Repeat(aiNodeAnim.getCPtr(value), count);
    aiNodeAnimVector ret = (cPtr == IntPtr.Zero) ? null : new aiNodeAnimVector(cPtr, true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    AssimpPINVOKE.aiNodeAnimVector_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    AssimpPINVOKE.aiNodeAnimVector_Reverse__SWIG_1(swigCPtr, index, count);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, aiNodeAnimVector values) {
    AssimpPINVOKE.aiNodeAnimVector_SetRange(swigCPtr, index, aiNodeAnimVector.getCPtr(values));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool Contains(aiNodeAnim value) {
    bool ret = AssimpPINVOKE.aiNodeAnimVector_Contains(swigCPtr, aiNodeAnim.getCPtr(value));
    return ret;
  }

  public int IndexOf(aiNodeAnim value) {
    int ret = AssimpPINVOKE.aiNodeAnimVector_IndexOf(swigCPtr, aiNodeAnim.getCPtr(value));
    return ret;
  }

  public int LastIndexOf(aiNodeAnim value) {
    int ret = AssimpPINVOKE.aiNodeAnimVector_LastIndexOf(swigCPtr, aiNodeAnim.getCPtr(value));
    return ret;
  }

  public bool Remove(aiNodeAnim value) {
    bool ret = AssimpPINVOKE.aiNodeAnimVector_Remove(swigCPtr, aiNodeAnim.getCPtr(value));
    return ret;
  }

}
