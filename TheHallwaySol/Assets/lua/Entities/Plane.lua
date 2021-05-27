Plane ={
    Active = true,
    Tag = "Ground",
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer ={
        Mesh = "Plano.mesh",
        Material = "TheHallway/Floor"
    },

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {1,1,1},
        RotationConstrains = {1,1,1}
    }
}