using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Rendering;
public class checkPoint : MonoBehaviour
{
    bool wasActivated;
    private void Start()
    {
        GetComponent<Renderer>().enabled = false;
        wasActivated = false;
    }
    private void OnTriggerEnter(Collider other)
    {
        if (!wasActivated)
        {
            other.GetComponent<playerBehavior>().updateRespawn(transform.position);
            wasActivated = true;
        }
    }


    //When dll is done call the update checkpoint in dll
}
