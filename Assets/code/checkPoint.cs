using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Rendering;
public class checkPoint : MonoBehaviour
{
    private void Start()
    {
        GetComponent<Renderer>().enabled = false;
    }
    private void OnTriggerEnter(Collider other)
    {
        other.GetComponent<playerBehavior>().updateRespawn(transform.position);
    }


    //When dll is done call the update checkpoint in dll
}
