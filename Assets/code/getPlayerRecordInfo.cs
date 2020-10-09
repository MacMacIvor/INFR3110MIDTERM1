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
    public int listnum2;
    public int listnum3;
    // Start is called before the first frame update
    void Start()
    {
        gameObject.GetComponent<PluginTester>().setTheFilePath();
        gameObject.GetComponent<PluginTester>().loadTheValues();
        theText.text = "'Player'\nCheckPoint1: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[0] + "\nCheckPoint2: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[1] +
            "\nCheckPoint3: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[2] + "\nCheckPoint4: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[3] +
            "\nCheckPoint5: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[4] + "\nTotalTime: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum)[5];
        theText2.text = "'Player'\nCheckPoint1: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum2)[0] + "\nCheckPoint2: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum2)[1] +
            "\nCheckPoint3: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum2)[2] + "\nCheckPoint4: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum2)[3] +
            "\nCheckPoint5: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum2)[4] + "\nTotalTime: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum2)[5];
        theText3.text = "'Player'\nCheckPoint1: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum3)[0] + "\nCheckPoint2: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum3)[1] +
            "\nCheckPoint3: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum3)[2] + "\nCheckPoint4: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum3)[3] +
            "\nCheckPoint5: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum3)[4] + "\nTotalTime: " + gameObject.GetComponent<PluginTester>().callTheInfo(listnum3)[5];
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
