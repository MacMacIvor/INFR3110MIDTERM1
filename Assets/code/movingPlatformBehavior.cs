using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class movingPlatformBehavior : MonoBehaviour
{
    [Range(0, 100)]
    public float distanceTillReverse = 1.0f;

    private float distanceMoved = 0.0f;

    private float isReversed = 1.0f;
    // Update is called once per frame
    void Update()
    {
        float distToMove = Vector3.forward.z * Time.deltaTime * isReversed;
        transform.position += new Vector3(0, 0, distToMove);
        distanceMoved += distToMove;

        if (distanceMoved >= distanceTillReverse || distanceMoved <= 0) {
            isReversed *= -1;
        }
    }
}
