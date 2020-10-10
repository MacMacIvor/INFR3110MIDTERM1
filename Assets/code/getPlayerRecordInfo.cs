using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class getPlayerRecordInfo : MonoBehaviour
{
    public Text theText;
    public Text theText2;
    public Text theText3;

    
    public int listnum;
    public int listnum2 = 1;
    public int listnum3 = 2;
    // Start is called before the first frame update
    void Start()
    {

        gameObject.GetComponent<PluginTester>().setTheFilePath();
        gameObject.GetComponent<PluginTester>().loadTheValues();
        theText.text = "'Player'\nCheckPoint1: " + gameObject.GetComponent<PluginTester>().callTheInfo(0)[0] + "\nCheckPoint2: " + gameObject.GetComponent<PluginTester>().callTheInfo(0)[1] +
             "\nCheckPoint3: " + gameObject.GetComponent<PluginTester>().callTheInfo(0)[2] + "\nCheckPoint4: " + gameObject.GetComponent<PluginTester>().callTheInfo(0)[3] +
             "\nCheckPoint5: " + gameObject.GetComponent<PluginTester>().callTheInfo(0)[4] + "\nTotalTime: " + gameObject.GetComponent<PluginTester>().callTheInfo(0)[5] +
             "\nScore: " + (1000 - gameObject.GetComponent<PluginTester>().callTheInfo(0)[5]).ToString();

        theText2.text = "'Player'\nCheckPoint1: " + gameObject.GetComponent<PluginTester>().callTheInfo(1)[0] + "\nCheckPoint2: " + gameObject.GetComponent<PluginTester>().callTheInfo(1)[1] +
            "\nCheckPoint3: " + gameObject.GetComponent<PluginTester>().callTheInfo(1)[2] + "\nCheckPoint4: " + gameObject.GetComponent<PluginTester>().callTheInfo(1)[3] +
            "\nCheckPoint5: " + gameObject.GetComponent<PluginTester>().callTheInfo(1)[4] + "\nTotalTime: " + gameObject.GetComponent<PluginTester>().callTheInfo(1)[5] +
             "\nScore: " + (1000 - gameObject.GetComponent<PluginTester>().callTheInfo(1)[5]).ToString();

        theText3.text = "'Player'\nCheckPoint1: " + gameObject.GetComponent<PluginTester>().callTheInfo(2)[0] + "\nCheckPoint2: " + gameObject.GetComponent<PluginTester>().callTheInfo(2)[1] +
            "\nCheckPoint3: " + gameObject.GetComponent<PluginTester>().callTheInfo(2)[2] + "\nCheckPoint4: " + gameObject.GetComponent<PluginTester>().callTheInfo(2)[3] +
            "\nCheckPoint5: " + gameObject.GetComponent<PluginTester>().callTheInfo(2)[4] + "\nTotalTime: " + gameObject.GetComponent<PluginTester>().callTheInfo(2)[5] +
             "\nScore: " + (1000 - gameObject.GetComponent<PluginTester>().callTheInfo(2)[5]).ToString();
        //gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[0];
    }

    // Update is called once per frame
    void Update()
    {
    }

    public void updateTheInfo()
    {
    }

}
