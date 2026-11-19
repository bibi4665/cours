package tp4;

public class BucketLeak extends Bucket {

    protected int leak;

    public  BucketLeak(int q, int l){
        super(q);
        this.leak = l;
    }

    @Override
    public String toString(){
        return "Bucket " + "quantity = " + this.quantity + " leak = " + this.leak;
    }

    @Override
    public void step(){
        if(this.quantity < leak){
            this.quantity = 0;
        }
        else {
            this.quantity -= leak;
        }
    }


}
