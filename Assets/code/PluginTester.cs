using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class PluginTester : MonoBehaviour
{
    const string DLL_NAME = "SavesDLLForMidterm1INFR3110";

    string filePath = "";

    [DllImport(DLL_NAME)]
    private static extern void startTimer();

    [DllImport(DLL_NAME)]
    private static extern void setFilePath(string filepath);


    // Start is called before the first frame update
    void Start()
    {
        filePath = Application.dataPath + "/SaveData/records.txt";
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            startTimer();
            setFilePath(filePath);
            Debug.Log("NoCrash?");
        }
    }
}
