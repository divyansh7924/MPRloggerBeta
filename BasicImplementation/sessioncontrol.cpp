protected override void OnSessionChange(SessionChangeDescription changeDescription)
{
    FileStream fs = new FileStream(@"c:\SystemActiveTimeInformation.txt",
    FileMode.OpenOrCreate, FileAccess.Write);
    StreamWriter sWriter = new StreamWriter(fs);
    sWriter.BaseStream.Seek(0, SeekOrigin.End);
    switch (changeDescription.Reason)
    {
        case SessionChangeReason.SessionLogon:
            sWriter.WriteLine("System Log On Time: \t " + DateTime.Now);
            break;
        case SessionChangeReason.SessionLogoff:
            sWriter.WriteLine("System Log Off Time: \t " + DateTime.Now);
            break;
        case SessionChangeReason.RemoteConnect:
            sWriter.WriteLine("System Remote Connect Time: \t " + DateTime.Now);
            break;
        case SessionChangeReason.RemoteDisconnect:
            sWriter.WriteLine("System Remote Disconnect Time: \t " + DateTime.Now);
            break;
        case SessionChangeReason.SessionLock:
            sWriter.WriteLine("System Locked Time: \t" + DateTime.Now);
            break;
        case SessionChangeReason.SessionUnlock:                    
            sWriter.WriteLine("System Unlocked Time: \t " + DateTime.Now);
            break; 
        default:
            break;
    }
    sWriter.Flush();
    sWriter.Close();
}

protected override void OnShutdown()
{
    FileStream fs = new FileStream(@"c:\SystemActiveTimeInformation.txt",
    FileMode.OpenOrCreate, FileAccess.Write);
    StreamWriter sWriter = new StreamWriter(fs);
    sWriter.BaseStream.Seek(0, SeekOrigin.End);
    sWriter.WriteLine("System Turn Off Time: \n " + DateTime.Now);
    sWriter.Flush();
    sWriter.Close();
}
