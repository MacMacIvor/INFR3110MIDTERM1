using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class PluginTester : MonoBehaviour
{
    const string DLL_NAME = "SavesDLLForMidterm1INFR3110";

    string filePath = "";

    [StructLayout(LayoutKind.Sequential)]
    struct playerScoreUnity
    {
        public float timeCheckPoint1;
        public float timeCheckPoint2;
        public float timeCheckPoint3;
        public float timeCheckPoint4;
        public float timeCheckPoint5;
        public float totalTime;
        public float timesDied;
    }

    playerScoreUnity test;

    [DllImport(DLL_NAME)]

    private static extern playerScoreUnity getInfo(int number);

    [DllImport(DLL_NAME)]
    private static extern void startTimer();

    [DllImport(DLL_NAME)]
    private static extern void setFilePath(string filepath);

    [DllImport(DLL_NAME)]
    private static extern void setScore(playerScoreUnity info);


    // Start is called before the first frame update
    void Start()
    {
        filePath = Application.dataPath + "/SaveData/records.txt";
        test.timeCheckPoint1 = 1;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            startTimer();
            setFilePath(filePath);
            setScore(test);
            Debug.Log(getInfo(0).timeCheckPoint1);
            Debug.Log("NoCrash?");
        }
    }
}
