class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        dig=[]
        let=[]
        for s in logs:
            try:
                int(s.split()[1])
                dig.append(s)
            except ValueError:
                let.append(s);
        let=sorted(let,key=lambda x:(x.split()[1:],x.split()[0]))
        return let+dig