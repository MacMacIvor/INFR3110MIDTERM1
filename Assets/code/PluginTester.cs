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
        public float timesDied;
        public float totalTime;
    }

    //Order things need to happen
    //set the filepath
    //Load Values (this loads the records in the file)
    //Start timer at start of gameplay
    //eachCheckpoint calls saveCheckPoint
    //The end screen calls the getInfo for the information
    //SetScore is a trap, don't use it, it's here for debug purposes


    //playerScoreUnity test;

    [DllImport(DLL_NAME)]
    private static extern playerScoreUnity getInfo(int number);

    [DllImport(DLL_NAME)]
    private static extern void startTimer();

    [DllImport(DLL_NAME)]
    private static extern void setFilePath(string filepath);

    [DllImport(DLL_NAME)]
   private static extern void setScore(playerScoreUnity info);

    [DllImport(DLL_NAME)]
    private static extern void saveCheckPoint(int checkpoint);

    [DllImport(DLL_NAME)]
    private static extern void loadValues();

    [DllImport(DLL_NAME)]
    private static extern void writeToFile();

    [DllImport(DLL_NAME)]
    private static extern double getTime();

    // Start is called before the first frame update
    void Start()
    {
        


        //test.timeCheckPoint1 = 1;
    }
    
    public double getTheTime()
    {
        return getTime();
    }

    public void setTheFilePath()
    {
        filePath = Application.dataPath + "/SaveData/records.txt";
        setFilePath(filePath);
    }

    public void loadTheValues()
    {
        loadValues();
    }
    
    public void startTheTimer()
    {
        startTimer();
    }

    public void saveTheCheckpoint(int number)
    {
        saveCheckPoint(number);
    }
        
    public float[] callTheInfo(int number)
    {
        

        float[] holder = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
        holder[0] = getInfo(number).timeCheckPoint1;
        holder[1] = getInfo(number).timeCheckPoint2;
        holder[2] = getInfo(number).timeCheckPoint3;
        holder[3] = getInfo(number).timeCheckPoint4;
        holder[4] = getInfo(number).timeCheckPoint5;
        holder[5] = getInfo(number).totalTime;
        holder[6] = getInfo(number).timesDied;
        return holder;
    }


    public void writeTheFile()
    {
        writeToFile();
    }


    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            //startTimer();
            setFilePath(filePath);
            writeToFile();
            //setScore(test);
            Debug.Log(getInfo(0).timeCheckPoint1);
            Debug.Log("NoCrash?");
        }
    }
}
