using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class respawnPlayer : MonoBehaviour
{
    playerBehavior player;
    private void OnTriggerEnter(Collider other)
    {
        other.GetComponent<playerBehavior>().respawnThePlayer();
    }
}
