﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;
public class toEnd : MonoBehaviour
{
    void Update()
    {
        if ((Input.GetMouseButtonDown(0)) && Input.mousePosition.x > transform.position.x - transform.localScale.x * 100.0f && Input.mousePosition.x < transform.position.x + transform.localScale.x * 100.0f && Input.mousePosition.y < transform.position.y + transform.localScale.y * 100.0f && Input.mousePosition.y > transform.position.y - transform.localScale.y * 100.0f)
        {
            SceneManager.LoadScene("EndScene");
        }
    }
}
